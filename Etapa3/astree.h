// Aluno: Gabriel Lando

#ifndef __ASTREE__
#define __ASTREE__

#define MAX_SONS 4

#define AST_SYMBOL_IDENTIFIER 1
#define AST_SYMBOL_STRING 2
#define AST_SYMBOL_CHAR 3
#define AST_SYMBOL_INTEGER 4
#define AST_SYMBOL_FLOAT 5
#define AST_SYMBOL_TRUE 6
#define AST_SYMBOL_FALSE 7
#define AST_PLUS 8
#define AST_MINUS 9
#define AST_MULT 10
#define AST_DIV 11
#define AST_LE 12
#define AST_LT 13
#define AST_GE 14
#define AST_GT 15
#define AST_EQ 16
#define AST_DIF 17
#define AST_OR 18
#define AST_AND 19
#define AST_NOT 20
#define AST_ARRAY_CALL 21
#define AST_FUNC_CALL 22
#define AST_FUNC_CALL_ARGS 23
#define AST_FUNC_CALL_ARGS_EXT 24
#define AST_MAYBE_ELSE 25
#define AST_LOOP 26
#define AST_WHILE 27
#define AST_IF_THEN 28
#define AST_PRINT_EXTRA_ELEMS 29
#define AST_PRINT_LIST 30
#define AST_ATTR_ARRAY 31
#define AST_ATTR 32
#define AST_PRINT 33
#define AST_RETURN 34
#define AST_READ 35
#define AST_CMD_SEQ 36
#define AST_CMD_BLOCK 37
#define AST_PARAM 38
#define AST_PARAM_LIST_EXT 39
#define AST_PARAM_LIST 40
#define AST_VET_VALUES 41
#define AST_VALUE 42
#define AST_KW_FLOAT 43
#define AST_KW_INT 44
#define AST_KW_BOOL 45
#define AST_KW_CHAR 46
#define AST_TYPE_AND_VALUE 47
#define AST_TYPE_AND_VALUE_ARRAY 48
#define AST_DECL_FUNC 49
#define AST_DECL_VAR 50
#define AST_DECL_LIST 51

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct astree_node {
    int type;
    HASH_NODE * symbol;
    struct astree_node * sons[MAX_SONS];
}
ASTREE_NODE;

ASTREE_NODE * AstreeCreate(int type, HASH_NODE * symbol, ASTREE_NODE * son0, ASTREE_NODE * son1, ASTREE_NODE * son2, ASTREE_NODE * son3);
void AstreePrint(int level, ASTREE_NODE * node);
void UncompileAST(FILE * out, ASTREE_NODE * root);

#endif