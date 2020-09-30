// Aluno: Gabriel Lando

%{
    /*#include <stdio.h>
    #include <stdlib.h>*/
    #include "astree.h"
    #include "hash.h"

    #define SYMBOL_AST(x) AstreeCreate(AST_SYMBOL, x, NULL, NULL, NULL, NULL, NULL)

    ASTREE_NODE * root = NULL;
%}

%union{
    HASH_NODE * symbol;
    ASTREE_NODE * astree;
}

%token KW_CHAR       
%token KW_INT        
%token KW_FLOAT      
%token KW_BOOL       

%token KW_IF         
%token KW_THEN       
%token KW_ELSE       
%token KW_WHILE      
%token KW_LOOP       
%token KW_READ       
%token KW_PRINT      
%token KW_RETURN     

%token OPERATOR_LE
%token OPERATOR_LT      
%token OPERATOR_GE      
%token OPERATOR_GT      
%token OPERATOR_EQ      
%token OPERATOR_DIF     
%token OPERATOR_OR     
%token OPERATOR_AND     
%token OPERATOR_NOT 

%token <symbol> TK_IDENTIFIER 
%token <symbol> LIT_INTEGER   
%token <symbol> LIT_FLOAT     
%token <symbol> LIT_TRUE      
%token <symbol> LIT_FALSE     
%token <symbol> LIT_CHAR      
%token <symbol> LIT_STRING    

%token TOKEN_ERROR

%left OPERATOR_OR OPERATOR_AND
%left OPERATOR_LE OPERATOR_LT OPERATOR_GE OPERATOR_GT OPERATOR_EQ OPERATOR_DIF OPERATOR_NOT
%left OPERATOR_PLUS OPERATOR_MINUS
%left OPERATOR_MULT OPERATOR_DIV

%type <astree> expr
%type <astree> lit
%type <astree> bin_expr
%type <astree> command
%type <astree> command_seq
%type <astree> command_block
%type <astree> print_elem
%type <astree> function_call_args
%type <astree> func_args_extra
%type <astree> maybe_else
%type <astree> command_control
%type <astree> print_extra_elems
%type <astree> print_list
%type <astree> command_attribute
%type <astree> param
%type <astree> param_list_ext
%type <astree> param_list
%type <astree> maybe_params
%type <astree> vet_value
%type <astree> vet_maybe_value
%type <astree> type
%type <astree> type_and_value
%type <astree> declaration
%type <astree> declaration_list

%start program

%{
    int getLineNumber();
    void yyerror();
    int yylex();
%}

%%

program: declaration_list                           { root = $1; AstreePrint(0, root); }
    ;

declaration_list: declaration declaration_list          { $$ = AstreeCreate(AST_DECL_LIST, 0, $1, $2, 0, 0); }
    |                                                   { $$ = 0; }
    ;

declaration: TK_IDENTIFIER '=' type_and_value ';'                       { $$ = AstreeCreate(AST_DECL_VAR, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '(' maybe_params ')' '=' type command_block ';'     { $$ = AstreeCreate(AST_DECL_FUNC, $1, $3, $6, $7, 0); }
    ;
    
type_and_value: type ':' lit                                            { $$ = AstreeCreate(AST_TYPE_AND_VALUE, 0, $1, $3, 0, 0); }
    | type '[' LIT_INTEGER ']' vet_maybe_value                          { $$ = AstreeCreate(AST_TYPE_AND_VALUE_ARRAY, $3, $1, $5, 0, 0); }
    ;


type: KW_CHAR                                   { $$ = AstreeCreate(AST_KW_CHAR, 0, 0, 0, 0, 0); }
    | KW_BOOL                                   { $$ = AstreeCreate(AST_KW_BOOL, 0, 0, 0, 0, 0); }
    | KW_INT                                    { $$ = AstreeCreate(AST_KW_INT, 0, 0, 0, 0, 0); }
    | KW_FLOAT                                  { $$ = AstreeCreate(AST_KW_FLOAT, 0, 0, 0, 0, 0); }
    ;

lit: LIT_CHAR                                   { $$ = AstreeCreate(AST_SYMBOL_CHAR, $1, 0, 0, 0, 0); }
    | LIT_INTEGER                               { $$ = AstreeCreate(AST_SYMBOL_INTEGER, $1, 0, 0, 0, 0); }
    | LIT_FLOAT                                 { $$ = AstreeCreate(AST_SYMBOL_FLOAT, $1, 0, 0, 0, 0); }
    | LIT_TRUE                                  { $$ = AstreeCreate(AST_SYMBOL_TRUE, $1, 0, 0, 0, 0); }
    | LIT_FALSE                                 { $$ = AstreeCreate(AST_SYMBOL_FALSE, $1, 0, 0, 0, 0); }
    ;

vet_maybe_value: ':' vet_value                  { $$ = AstreeCreate(AST_VALUE, 0, $2, 0, 0, 0); }
    |                                           { $$ = 0; }
    ;

vet_value: lit vet_value                        { $$ = AstreeCreate(AST_VET_VALUES, 0, $1, $2, 0, 0); }
    | lit                                       { $$ = $1; }
    ;

maybe_params: param_list                        { $$ = $1; }
    |                                           { $$ = 0; }
    ;
    
param_list: param param_list_ext                { $$ = AstreeCreate(AST_PARAM_LIST, 0, $1, $2, 0, 0); }
    ;

param_list_ext: ',' param param_list_ext        { $$ = AstreeCreate(AST_PARAM_LIST_EXT, 0, $2, $3, 0, 0); }
    |                                           { $$ = 0; }
    ;

param: TK_IDENTIFIER '=' type                   { $$ = AstreeCreate(AST_PARAM, $1, $3, 0, 0, 0); }                   
    ;

command_block: '{' command_seq '}'              { $$ = AstreeCreate(AST_CMD_BLOCK, 0, $2, 0, 0, 0); }
    ;

command_seq: command_seq command                { $$ = AstreeCreate(AST_CMD_SEQ, 0, $1, $2, 0, 0); }
    |                                           { $$ = 0; }
    ;

command: command_attribute                      { $$ = $1; }
    | KW_READ TK_IDENTIFIER                     { $$ = AstreeCreate(AST_READ, $2, 0, 0, 0, 0); }             
    | KW_RETURN expr                            { $$ = AstreeCreate(AST_RETURN, 0, $2, 0, 0, 0); }
    | KW_PRINT print_list                       { $$ = AstreeCreate(AST_PRINT, 0, $2, 0, 0, 0); }
    | command_control                           { $$ = $1; }
    | command_block                             { $$ = $1; }
    |                                           { $$ = 0; }
    ;

command_attribute: TK_IDENTIFIER '=' expr               { $$ = AstreeCreate(AST_ATTR, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']' '=' expr               { $$ = AstreeCreate(AST_ATTR_ARRAY, $1, $3, $6, 0, 0); }
    ;

print_list:  print_elem print_extra_elems               { $$ = AstreeCreate(AST_PRINT_LIST, 0, $1, $2, 0, 0); }
    ;

print_extra_elems: ',' print_elem print_extra_elems     { $$ = AstreeCreate(AST_PRINT_EXTRA_ELEMS, 0, $2, $3, 0, 0); }
    |                                                   { $$ = 0; }
    ;

print_elem: LIT_STRING                                  { $$ = AstreeCreate(AST_SYMBOL_STRING, $1, 0, 0, 0, 0); }
    | expr                                              { $$ = $1; }
    ;

command_control: KW_IF '(' expr ')' KW_THEN command maybe_else              { $$ = AstreeCreate(AST_IF_THEN, 0, $3, $6, $7, 0); }
    | KW_WHILE '(' expr ')' command                                         { $$ = AstreeCreate(AST_WHILE, 0, $3, $5, 0, 0); }
    | KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' command      { $$ = AstreeCreate(AST_LOOP, $3, $5, $7, $9, $11); }
    ;

maybe_else: KW_ELSE command                             { $$ = AstreeCreate(AST_MAYBE_ELSE, 0, $2, 0, 0, 0); }
    |                                                   { $$ = 0; }
    ;

expr: bin_expr                                          { $$ = $1; }
    | '(' expr ')'                                      { $$ = $2; }
    | OPERATOR_NOT expr                                 { $$ = AstreeCreate(AST_NOT, 0, $2, 0, 0, 0); }
    | TK_IDENTIFIER                                     { $$ = AstreeCreate(AST_SYMBOL_IDENTIFIER, $1, 0, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']'                        { $$ = AstreeCreate(AST_ARRAY_CALL, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '(' function_call_args ')'          { $$ = AstreeCreate(AST_FUNC_CALL, $1, $3, 0, 0, 0); }
    | lit                                               { $$ = $1; }
    ;

bin_expr: expr OPERATOR_PLUS expr                   { $$ = AstreeCreate(AST_PLUS, 0, $1, $3, 0, 0); }
    | expr OPERATOR_MINUS expr                      { $$ = AstreeCreate(AST_MINUS, 0, $1, $3, 0, 0); }
    | expr OPERATOR_MULT expr                       { $$ = AstreeCreate(AST_MULT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_DIV expr                        { $$ = AstreeCreate(AST_DIV, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LE expr                         { $$ = AstreeCreate(AST_LE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LT expr                         { $$ = AstreeCreate(AST_LT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_GE expr                         { $$ = AstreeCreate(AST_GE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_GT expr                         { $$ = AstreeCreate(AST_GT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_EQ expr                         { $$ = AstreeCreate(AST_EQ, 0, $1, $3, 0, 0); }
    | expr OPERATOR_DIF expr                        { $$ = AstreeCreate(AST_DIF, 0, $1, $3, 0, 0); }
    | expr OPERATOR_OR expr                         { $$ = AstreeCreate(AST_OR, 0, $1, $3, 0, 0); }
    | expr OPERATOR_AND expr                        { $$ = AstreeCreate(AST_AND, 0, $1, $3, 0, 0); }
    ;


function_call_args: expr func_args_extra            { $$ = AstreeCreate(AST_FUNC_CALL_ARGS, 0, $1, $2, 0, 0); }     
    |                                               { $$ = 0; }
    ;

func_args_extra: ',' expr func_args_extra           { $$ = AstreeCreate(AST_FUNC_CALL_ARGS_EXT, 0, $2, $3, 0, 0); }
    |                                               { $$ = 0; }
    ;

%%

void yyerror()
{
    fprintf(stderr, "Syntax error at line %d.\n", getLineNumber());
    exit(3);
}

ASTREE_NODE * GetAST(){
	return root;
}