// Aluno: Gabriel Lando

#include "hash.h"
#include "astree.h"
#include <stdlib.h>
#include <stdio.h>

ASTREE_NODE * AstreeCreate(int type, HASH_NODE * symbol, ASTREE_NODE * son0, ASTREE_NODE * son1, ASTREE_NODE * son2, ASTREE_NODE * son3) {
    ASTREE_NODE * node = (ASTREE_NODE *)calloc(1, sizeof(ASTREE_NODE));
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

    for(int i=0; i<level; ++i)
        fprintf(stderr, "  ");

    fprintf(stderr, "AST (");
    switch(node->type) {
        case AST_SYMBOL_IDENTIFIER: fprintf(stderr,"AST_SYMBOL_IDENTIFIER"); break;
        case AST_SYMBOL_STRING: fprintf(stderr,"AST_SYMBOL_STRING"); break;               
        case AST_SYMBOL_CHAR: fprintf(stderr,"AST_SYMBOL_CHAR"); break;                 
        case AST_SYMBOL_INTEGER: fprintf(stderr,"AST_SYMBOL_INTEGER"); break;              
        case AST_SYMBOL_FLOAT: fprintf(stderr,"AST_SYMBOL_FLOAT"); break;                
        case AST_SYMBOL_TRUE: fprintf(stderr,"AST_SYMBOL_TRUE"); break;                 
        case AST_SYMBOL_FALSE: fprintf(stderr,"AST_SYMBOL_FALSE"); break;                
        case AST_PLUS: fprintf(stderr,"AST_PLUS"); break;
        case AST_MINUS: fprintf(stderr,"AST_MINUS"); break;
        case AST_MULT: fprintf(stderr,"AST_MULT"); break;
        case AST_DIV: fprintf(stderr,"AST_DIV"); break;
        case AST_LE: fprintf(stderr,"AST_LE"); break;
        case AST_LT: fprintf(stderr,"AST_LT"); break;
        case AST_GE: fprintf(stderr,"AST_GE"); break;
        case AST_GT: fprintf(stderr,"AST_GT"); break;
        case AST_EQ: fprintf(stderr,"AST_EQ"); break;
        case AST_DIF: fprintf(stderr,"AST_DIF"); break;
        case AST_OR: fprintf(stderr,"AST_OR"); break;
        case AST_AND: fprintf(stderr,"AST_AND"); break;
        case AST_NOT: fprintf(stderr,"AST_NOT"); break;
        case AST_ARRAY_CALL: fprintf(stderr, "AST_ARRAY_CALL"); break;        
        case AST_FUNC_CALL: fprintf(stderr, "AST_FUNC_CALL"); break;         
        case AST_FUNC_CALL_ARGS: fprintf(stderr, "AST_FUNC_CALL_ARGS"); break;    
        case AST_FUNC_CALL_ARGS_EXT: fprintf(stderr, "AST_FUNC_CALL_ARGS_EXT"); break;
        case AST_MAYBE_ELSE: fprintf(stderr, "AST_MAYBE_ELSE"); break;          
        case AST_LOOP: fprintf(stderr, "AST_LOOP"); break;                
        case AST_WHILE: fprintf(stderr, "AST_WHILE"); break;               
        case AST_IF_THEN: fprintf(stderr, "AST_IF_THEN"); break;   
        case AST_PRINT_EXTRA_ELEMS: fprintf(stderr, "AST_PRINT_EXTRA_ELEMS"); break;   
        case AST_PRINT_LIST: fprintf(stderr, "AST_PRINT_LIST"); break;          
        case AST_ATTR_ARRAY: fprintf(stderr, "AST_ATTR_ARRAY"); break;          
        case AST_ATTR: fprintf(stderr, "AST_ATTR"); break;                
        case AST_PRINT: fprintf(stderr, "AST_PRINT"); break;               
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;              
        case AST_READ: fprintf(stderr, "AST_READ"); break;      
        case AST_CMD_SEQ: fprintf(stderr, "AST_CMD_SEQ"); break;             
        case AST_CMD_BLOCK: fprintf(stderr, "AST_CMD_BLOCK"); break;           
        case AST_PARAM: fprintf(stderr, "AST_PARAM"); break;               
        case AST_PARAM_LIST_EXT: fprintf(stderr, "AST_PARAM_LIST_EXT"); break;      
        case AST_PARAM_LIST: fprintf(stderr, "AST_PARAM_LIST"); break;          
        case AST_VET_VALUES: fprintf(stderr, "AST_VET_VALUES"); break;          
        case AST_VALUE: fprintf(stderr, "AST_VALUE"); break;               
        case AST_KW_FLOAT: fprintf(stderr, "AST_KW_FLOAT"); break;            
        case AST_KW_INT: fprintf(stderr, "AST_KW_INT"); break;              
        case AST_KW_BOOL: fprintf(stderr, "AST_KW_BOOL"); break;             
        case AST_KW_CHAR: fprintf(stderr, "AST_KW_CHAR"); break;             
        case AST_TYPE_AND_VALUE: fprintf(stderr, "AST_TYPE_AND_VALUE"); break;      
        case AST_TYPE_AND_VALUE_ARRAY: fprintf(stderr, "AST_TYPE_AND_VALUE_ARRAY"); break;
        case AST_DECL_FUNC: fprintf(stderr, "AST_DECL_FUNC"); break;           
        case AST_DECL_VAR: fprintf(stderr, "AST_DECL_VAR"); break;            
        case AST_DECL_LIST: fprintf(stderr, "AST_DECL_LIST"); break;                     
        default: fprintf(stderr,"AST_UNKNOWN"); break;
    }

    if (node->symbol != 0)
        fprintf(stderr, ",%s)\n", node->symbol->text);
    else
        fprintf(stderr, ",0)\n");

    for(int i=0; i < MAX_SONS; ++i)
        AstreePrint(level+1, node->sons[i]);

    return;
}

void UncompileAST(FILE * out, ASTREE_NODE * root) {

    if (root == NULL)
        return;

    switch (root->type) {
        case AST_SYMBOL_IDENTIFIER: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_STRING: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_CHAR: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_INTEGER: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_FLOAT: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_TRUE: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_SYMBOL_FALSE: {
            fprintf(out, "%s", root->symbol->text);
            fflush(out);
            break;
        } 

        case AST_PLUS: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " + ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_MINUS: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " - ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_MULT: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " * ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_DIV: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " / ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_LE: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " <= ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_LT: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " < ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_GE: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " >= ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_GT: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " > ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_EQ: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " == ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_DIF: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " != ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_OR: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " | ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_AND: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ^ ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_NOT: {
            fprintf(out, "~");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_ARRAY_CALL: {
            fprintf(out, "%s [", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, "]");
            fflush(out);
            break;
        }

        case AST_FUNC_CALL: {
            fprintf(out, "%s (", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ")");
            fflush(out);
            break;
        }

        case AST_FUNC_CALL_ARGS: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_FUNC_CALL_ARGS_EXT: {
            fprintf(out, ", ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_MAYBE_ELSE: {
            fprintf(out, "else ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_LOOP: {
            fprintf(out, "loop (%s: ", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ", ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            fprintf(out, ", ");
            fflush(out);
            UncompileAST(out, root->sons[2]);
            fprintf(out, ") ");
            fflush(out);
            UncompileAST(out, root->sons[3]);
            break;
        }

        case AST_WHILE: {
            fprintf(out, "while (");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ") ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_IF_THEN: {
            fprintf(out, "if (");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ") then ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[2]);
            break;
        }


        case AST_PRINT_EXTRA_ELEMS: {
            fprintf(out, ", ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_PRINT_LIST: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_PRINT: {
            fprintf(out, "print ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_ATTR_ARRAY: {
            fprintf(out, "%s[", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, "] = ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_ATTR: {
            fprintf(out, "%s = ", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_RETURN: {
            fprintf(out, "return ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_READ: {
            fprintf(out, "read %s", root->symbol->text);
            fflush(out);
            break;
        }

        case AST_CMD_SEQ: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, "\n");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_CMD_BLOCK: {
            fprintf(out, "{");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, "\n}");
            fflush(out);
            break;
        }

        case AST_PARAM: {
            fprintf(out, "%s = ", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            break;
        }

        case AST_PARAM_LIST_EXT: {
            fprintf(out, ", ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_PARAM_LIST: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_VET_VALUES: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_VALUE: {
            fprintf(out, ": ");
            fflush(out);
            UncompileAST(out, root->sons[0]);
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
            UncompileAST(out, root->sons[0]);
            fprintf(out, ": ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_TYPE_AND_VALUE_ARRAY: {
            UncompileAST(out, root->sons[0]);
            fprintf(out, "[%s]", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[1]);
            break;
        }

        case AST_DECL_FUNC: {
            fprintf(out, "%s (", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ") = ");
            fflush(out);
            UncompileAST(out, root->sons[1]);
            fprintf(out, " ");
            fflush(out);
            UncompileAST(out, root->sons[2]);
            fprintf(out, ";\n");
            fflush(out);
            break;
        }

        case AST_DECL_VAR: {
            fprintf(out, "%s = ", root->symbol->text);
            fflush(out);
            UncompileAST(out, root->sons[0]);
            fprintf(out, ";\n");
            fflush(out);
            break;
        }

        case AST_DECL_LIST: {
            UncompileAST(out, root->sons[0]);
            UncompileAST(out, root->sons[1]);
            break;
        }

        default:
            break;
    }
}

char* decompileTree(ASTREE_NODE *ast) {
    if (ast) {
        switch (ast->type) {
            case AST_SYMBOL_IDENTIFIER: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_STRING: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_CHAR: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_INTEGER: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_FLOAT: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_TRUE: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            }

            case AST_SYMBOL_FALSE: {
                char *buffer = (char *) calloc(strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "%s", ast->symbol->text);
                return buffer;
            } 

            case AST_PLUS: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s + %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_MINUS: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s - %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_MULT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s * %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_DIV: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s / %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_LE: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(5 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s <= %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_LT: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s < %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_GE: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(5 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s >= %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_GT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s > %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_EQ: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(5 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s == %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_DIF: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(5 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s != %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_OR: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s | %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_AND: {
                
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s ^ %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_NOT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "!%s", son_0_txt);
                return buffer;
            }

            case AST_ARRAY_CALL: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(4 + strlen(ast->symbol->text) + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "%s [%s]", ast->symbol->text, son_0_txt);
                return buffer;
            }

            case AST_FUNC_CALL: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(4 + strlen(ast->symbol->text) + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "%s (%s)", ast->symbol->text, son_0_txt);
                return buffer;
            }

            case AST_FUNC_CALL_ARGS: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_FUNC_CALL_ARGS_EXT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, ", %s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_MAYBE_ELSE: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(6 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "else %s", son_0_txt);
                return buffer;
            }

            case AST_LOOP: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *son_2_txt = decompileTree(ast->sons[2]);
                char *son_3_txt = decompileTree(ast->sons[3]);
                char *buffer = (char *) calloc(15 + strlen(ast->symbol->text) + strlen(son_0_txt) + strlen(son_1_txt) + strlen(son_2_txt) + strlen(son_3_txt), sizeof(char));
                sprintf(buffer, "loop (%s: %s, %s, %s) %s", ast->symbol->text, son_0_txt, son_1_txt, son_2_txt, son_3_txt);
                return buffer;
            }

            case AST_WHILE: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(10 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "while (%s) %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_IF_THEN: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *son_2_txt = decompileTree(ast->sons[2]);
                char *buffer = (char *) calloc(13 + strlen(son_0_txt) + strlen(son_1_txt) + strlen(son_2_txt), sizeof(char));
                sprintf(buffer, "if (%s) then %s %s", son_0_txt, son_1_txt, son_2_txt);
                return buffer;
            }


            case AST_PRINT_EXTRA_ELEMS: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, ", %s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_PRINT_LIST: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_PRINT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(7 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "print %s", son_0_txt);
                return buffer;
            }

            case AST_ATTR_ARRAY: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char* son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(6 +strlen(son_0_txt) + strlen(ast->symbol->text) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s[%s] = %s", ast->symbol->text, son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_ATTR: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(4 + strlen(ast->symbol->text) + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "%s = %s", ast->symbol->text, son_0_txt);
                return buffer;
            }

            case AST_RETURN: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(8 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "return %s", son_0_txt);
                return buffer;
            }

            case AST_READ: {
                char *buffer = (char *) calloc(6 + strlen(ast->symbol->text), sizeof(char));
                sprintf(buffer, "read %s", ast->symbol->text);
                return buffer;
            }


            case AST_CMD_SEQ: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s\n%s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_CMD_BLOCK: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(5 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "{\n%s\n}", son_0_txt);
                return buffer;
            }

            case AST_PARAM: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(4 + strlen(ast->symbol->text) + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "%s = %s", ast->symbol->text, son_0_txt);
                return buffer;
            }

            case AST_PARAM_LIST_EXT: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(4 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, ", %s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_PARAM_LIST: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_VET_VALUES: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(2 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_VALUE: {
                char *son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(3 + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, ": %s", son_0_txt);
                return buffer;
            }

            case AST_KW_FLOAT: {
                return "float";
            }

            case AST_KW_INT: {
                return "int";
            }

            case AST_KW_BOOL: {
                return "bool";
            }

            case AST_KW_CHAR: {
                return "char";
            }

            case AST_TYPE_AND_VALUE: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char* son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(3 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s: %s", son_0_txt, son_1_txt);
                return buffer;
            }

            case AST_TYPE_AND_VALUE_ARRAY: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char* son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(3 +strlen(son_0_txt) + strlen(ast->symbol->text) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s[%s]%s", son_0_txt, ast->symbol->text, son_1_txt);
                return buffer;
            }

            case AST_DECL_FUNC: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char* son_1_txt = decompileTree(ast->sons[1]);
                char* son_2_txt = decompileTree(ast->sons[2]);
                char *buffer = (char *) calloc(10 + strlen(ast->symbol->text) + strlen(son_0_txt) + strlen(son_1_txt) + strlen(son_2_txt), sizeof(char));
                sprintf(buffer, "%s ( %s) = %s %s;\n", ast->symbol->text, son_0_txt, son_1_txt, son_2_txt);
                return buffer;
            }

            case AST_DECL_VAR: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char *buffer = (char *) calloc(6 + strlen(ast->symbol->text) + strlen(son_0_txt), sizeof(char));
                sprintf(buffer, "%s = %s;\n", ast->symbol->text, son_0_txt);
                return buffer;
            }

            case AST_DECL_LIST: {
                char* son_0_txt = decompileTree(ast->sons[0]);
                char* son_1_txt = decompileTree(ast->sons[1]);
                char *buffer = (char *) calloc(1 + strlen(son_0_txt) + strlen(son_1_txt), sizeof(char));
                sprintf(buffer, "%s%s", son_0_txt, son_1_txt);
                return buffer;
            }

            default:
                return "";

        }

        return "";
    } else {
        return "";
    }
}