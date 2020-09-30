// Aluno: Gabriel Lando

#include "hash.h"
#include "astree.h"
#include <stdlib.h>
#include <stdio.h>

ASTREE_NODE * AstreeCreate(int type, HASH_NODE * symbol, ASTREE_NODE * son0, ASTREE_NODE * son1, ASTREE_NODE * son2, ASTREE_NODE * son3) {
    ASTREE_NODE * node = (ASTREE_NODE * ) calloc(1, sizeof(ASTREE_NODE));
    node -> type = type;
    node -> symbol = symbol;
    node -> sons[0] = son0;
    node -> sons[1] = son1;
    node -> sons[2] = son2;
    node -> sons[3] = son3;

    return node;
}

void AstreePrint(int level, ASTREE_NODE * node) {
    if (node == 0) return;

    for (int i = 0; i < level; ++i)
        fprintf(stderr, "  ");

    fprintf(stderr, "AST (");
    switch (node -> type) {
    case AST_SYMBOL_IDENTIFIER:
        fprintf(stderr, "AST_SYMBOL_IDENTIFIER");
        break;
    case AST_SYMBOL_STRING:
        fprintf(stderr, "AST_SYMBOL_STRING");
        break;
    case AST_SYMBOL_CHAR:
        fprintf(stderr, "AST_SYMBOL_CHAR");
        break;
    case AST_SYMBOL_INTEGER:
        fprintf(stderr, "AST_SYMBOL_INTEGER");
        break;
    case AST_SYMBOL_FLOAT:
        fprintf(stderr, "AST_SYMBOL_FLOAT");
        break;
    case AST_SYMBOL_TRUE:
        fprintf(stderr, "AST_SYMBOL_TRUE");
        break;
    case AST_SYMBOL_FALSE:
        fprintf(stderr, "AST_SYMBOL_FALSE");
        break;
    case AST_PLUS:
        fprintf(stderr, "AST_PLUS");
        break;
    case AST_MINUS:
        fprintf(stderr, "AST_MINUS");
        break;
    case AST_MULT:
        fprintf(stderr, "AST_MULT");
        break;
    case AST_DIV:
        fprintf(stderr, "AST_DIV");
        break;
    case AST_LE:
        fprintf(stderr, "AST_LE");
        break;
    case AST_LT:
        fprintf(stderr, "AST_LT");
        break;
    case AST_GE:
        fprintf(stderr, "AST_GE");
        break;
    case AST_GT:
        fprintf(stderr, "AST_GT");
        break;
    case AST_EQ:
        fprintf(stderr, "AST_EQ");
        break;
    case AST_DIF:
        fprintf(stderr, "AST_DIF");
        break;
    case AST_OR:
        fprintf(stderr, "AST_OR");
        break;
    case AST_AND:
        fprintf(stderr, "AST_AND");
        break;
    case AST_NOT:
        fprintf(stderr, "AST_NOT");
        break;
    case AST_ARRAY_CALL:
        fprintf(stderr, "AST_ARRAY_CALL");
        break;
    case AST_FUNC_CALL:
        fprintf(stderr, "AST_FUNC_CALL");
        break;
    case AST_FUNC_CALL_ARGS:
        fprintf(stderr, "AST_FUNC_CALL_ARGS");
        break;
    case AST_FUNC_CALL_ARGS_EXT:
        fprintf(stderr, "AST_FUNC_CALL_ARGS_EXT");
        break;
    case AST_MAYBE_ELSE:
        fprintf(stderr, "AST_MAYBE_ELSE");
        break;
    case AST_LOOP:
        fprintf(stderr, "AST_LOOP");
        break;
    case AST_WHILE:
        fprintf(stderr, "AST_WHILE");
        break;
    case AST_IF_THEN:
        fprintf(stderr, "AST_IF_THEN");
        break;
    case AST_PRINT_EXTRA_ELEMS:
        fprintf(stderr, "AST_PRINT_EXTRA_ELEMS");
        break;
    case AST_PRINT_LIST:
        fprintf(stderr, "AST_PRINT_LIST");
        break;
    case AST_ATTR_ARRAY:
        fprintf(stderr, "AST_ATTR_ARRAY");
        break;
    case AST_ATTR:
        fprintf(stderr, "AST_ATTR");
        break;
    case AST_PRINT:
        fprintf(stderr, "AST_PRINT");
        break;
    case AST_RETURN:
        fprintf(stderr, "AST_RETURN");
        break;
    case AST_READ:
        fprintf(stderr, "AST_READ");
        break;
    case AST_CMD_SEQ:
        fprintf(stderr, "AST_CMD_SEQ");
        break;
    case AST_CMD_BLOCK:
        fprintf(stderr, "AST_CMD_BLOCK");
        break;
    case AST_PARAM:
        fprintf(stderr, "AST_PARAM");
        break;
    case AST_PARAM_LIST_EXT:
        fprintf(stderr, "AST_PARAM_LIST_EXT");
        break;
    case AST_PARAM_LIST:
        fprintf(stderr, "AST_PARAM_LIST");
        break;
    case AST_VET_VALUES:
        fprintf(stderr, "AST_VET_VALUES");
        break;
    case AST_VALUE:
        fprintf(stderr, "AST_VALUE");
        break;
    case AST_KW_FLOAT:
        fprintf(stderr, "AST_KW_FLOAT");
        break;
    case AST_KW_INT:
        fprintf(stderr, "AST_KW_INT");
        break;
    case AST_KW_BOOL:
        fprintf(stderr, "AST_KW_BOOL");
        break;
    case AST_KW_CHAR:
        fprintf(stderr, "AST_KW_CHAR");
        break;
    case AST_TYPE_AND_VALUE:
        fprintf(stderr, "AST_TYPE_AND_VALUE");
        break;
    case AST_TYPE_AND_VALUE_ARRAY:
        fprintf(stderr, "AST_TYPE_AND_VALUE_ARRAY");
        break;
    case AST_DECL_FUNC:
        fprintf(stderr, "AST_DECL_FUNC");
        break;
    case AST_DECL_VAR:
        fprintf(stderr, "AST_DECL_VAR");
        break;
    case AST_DECL_LIST:
        fprintf(stderr, "AST_DECL_LIST");
        break;
    default:
        fprintf(stderr, "AST_UNKNOWN");
        break;
    }

    if (node -> symbol != 0)
        fprintf(stderr, ",%s)\n", node -> symbol -> text);
    else
        fprintf(stderr, ",0)\n");

    for (int i = 0; i < MAX_SONS; ++i)
        AstreePrint(level + 1, node -> sons[i]);

    return;
}

void UncompileAST(FILE * out, ASTREE_NODE * root) {

    if (root == NULL)
        return;

    switch (root -> type) {
    case AST_SYMBOL_IDENTIFIER: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_STRING: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_CHAR: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_INTEGER: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_FLOAT: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_TRUE: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_SYMBOL_FALSE: {
        fprintf(out, "%s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_PLUS: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " + ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_MINUS: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " - ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_MULT: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " * ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_DIV: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " / ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_LE: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " <= ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_LT: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " < ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_GE: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " >= ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_GT: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " > ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_EQ: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " == ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_DIF: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " != ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_OR: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " | ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_AND: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ^ ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_NOT: {
        fprintf(out, "~");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_ARRAY_CALL: {
        fprintf(out, "%s [", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, "]");
        fflush(out);
        break;
    }

    case AST_FUNC_CALL: {
        fprintf(out, "%s (", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ")");
        fflush(out);
        break;
    }

    case AST_FUNC_CALL_ARGS: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_FUNC_CALL_ARGS_EXT: {
        fprintf(out, ", ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_MAYBE_ELSE: {
        fprintf(out, "else ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_LOOP: {
        fprintf(out, "loop (%s: ", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ", ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        fprintf(out, ", ");
        fflush(out);
        UncompileAST(out, root -> sons[2]);
        fprintf(out, ") ");
        fflush(out);
        UncompileAST(out, root -> sons[3]);
        break;
    }

    case AST_WHILE: {
        fprintf(out, "while (");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ") ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_IF_THEN: {
        fprintf(out, "if (");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ") then ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[2]);
        break;
    }

    case AST_PRINT_EXTRA_ELEMS: {
        fprintf(out, ", ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_PRINT_LIST: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_PRINT: {
        fprintf(out, "print ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_ATTR_ARRAY: {
        fprintf(out, "%s[", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, "] = ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_ATTR: {
        fprintf(out, "%s = ", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_RETURN: {
        fprintf(out, "return ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_READ: {
        fprintf(out, "read %s", root -> symbol -> text);
        fflush(out);
        break;
    }

    case AST_CMD_SEQ: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, "\n");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_CMD_BLOCK: {
        fprintf(out, "{");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, "\n}");
        fflush(out);
        break;
    }

    case AST_PARAM: {
        fprintf(out, "%s = ", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_PARAM_LIST_EXT: {
        fprintf(out, ", ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_PARAM_LIST: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_VET_VALUES: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_VALUE: {
        fprintf(out, ": ");
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        break;
    }

    case AST_KW_FLOAT: {
        fprintf(out, "float");
        fflush(out);
        break;
    }

    case AST_KW_INT: {
        fprintf(out, "int");
        fflush(out);
        break;
    }

    case AST_KW_BOOL: {
        fprintf(out, "bool");
        fflush(out);
        break;
    }

    case AST_KW_CHAR: {
        fprintf(out, "char");
        fflush(out);
        break;
    }

    case AST_TYPE_AND_VALUE: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ": ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_TYPE_AND_VALUE_ARRAY: {
        UncompileAST(out, root -> sons[0]);
        fprintf(out, "[%s]", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    case AST_DECL_FUNC: {
        fprintf(out, "%s (", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ") = ");
        fflush(out);
        UncompileAST(out, root -> sons[1]);
        fprintf(out, " ");
        fflush(out);
        UncompileAST(out, root -> sons[2]);
        fprintf(out, ";\n");
        fflush(out);
        break;
    }

    case AST_DECL_VAR: {
        fprintf(out, "%s = ", root -> symbol -> text);
        fflush(out);
        UncompileAST(out, root -> sons[0]);
        fprintf(out, ";\n");
        fflush(out);
        break;
    }

    case AST_DECL_LIST: {
        UncompileAST(out, root -> sons[0]);
        UncompileAST(out, root -> sons[1]);
        break;
    }

    default:
        break;
    }
}
