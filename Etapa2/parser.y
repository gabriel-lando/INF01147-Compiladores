// Aluno: Gabriel Lando

%{
    #include <stdio.h>
    #include <stdlib.h>
    int getLineNumber();
    void yyerror();
%}

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
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_DIF  
%token TK_IDENTIFIER 

%token LIT_INTEGER   
%token LIT_FLOAT     
%token LIT_TRUE      
%token LIT_FALSE     
%token LIT_CHAR      
%token LIT_STRING    
%token TOKEN_ERROR

%left '|' '~'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/' '^'


%%

programa: decl
    ;
    
decl: dec ';' decl
    | 
    ;

dec: TK_IDENTIFIER '=' types ':' literals
    | TK_IDENTIFIER '=' types '[' LIT_INTEGER ']' ':' lit_list
    | TK_IDENTIFIER '=' types '[' LIT_INTEGER ']'
    | TK_IDENTIFIER '(' params_func ')' '=' types block
    ;

block: '{' command_list '}'
    ;

command_list: cmd command_list
    | 
    ;

cmd: TK_IDENTIFIER '=' expr
    | TK_IDENTIFIER '[' expr ']' '=' expr
    | KW_PRINT print_list
    | KW_READ TK_IDENTIFIER
    | KW_RETURN expr
    | KW_IF '(' expr ')' KW_THEN cmd
    | KW_IF '(' expr ')' KW_THEN cmd KW_ELSE cmd
    | KW_WHILE '(' expr ')' cmd
    | KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' cmd
    | block
    | 
    ;

print_list: print_cmd rest_print_list
    ;

rest_print_list: ',' print_cmd rest_print_list
    | 
    ;

print_cmd: LIT_STRING
    | expr
    ;

expr: TK_IDENTIFIER
    | TK_IDENTIFIER '[' expr ']'
    | TK_IDENTIFIER '(' func_args ')'
    | literals
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '>' expr
    | expr '<' expr
    | expr '|' expr
    | expr '^' expr
    | expr '~' expr
    | expr OPERATOR_LE expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_DIF expr
    | '(' expr ')'
    ;

func_args: expr rest_func_args
    | 
    ;

rest_func_args: ',' expr rest_func_args
    | 
    ;

params_func: params params_resto
    | 
    ;

params_resto: ',' params params_resto
    | 
    ;

params: TK_IDENTIFIER '=' types
    ;

types: 
    | KW_CHAR
    | KW_INT
    | KW_FLOAT
    | KW_BOOL
    ;

lit_list: literals lit_list
    | 
    ;

literals: LIT_CHAR
    | LIT_FALSE
    | LIT_TRUE
    | LIT_FLOAT
    | LIT_INTEGER
    ;

%%

void yyerror()
{
    fprintf(stderr, "Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
