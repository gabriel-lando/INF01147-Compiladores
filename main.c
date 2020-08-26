#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

//lex.yy.h
int yylex();
extern char * yytext;
extern FILE * yyin;

int isRunning(void);

int main(int argc, char ** argv) {
    FILE * gold = 0;
    int token = 0;
    int answar = 0;
    int nota = 0;
    int i = 1;
    fprintf(stderr, "Rodando main do prof. \n");

    if (argc < 3) {
        printf("call: ./etapa1 input.txt output.txt \n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1], "r"))) {
        printf("Cannot open file %s... \n", argv[1]);
        exit(1);
    }
    while (isRunning()) {
        token = yylex();

        if (!isRunning())
            break;

        fprintf(stderr, "%d=%s ", i, yytext);
        switch(token) {
            case KW_CHAR: printf("Char\n"); break;
            case KW_INT: printf("Int\n"); break;
            case KW_FLOAT: printf("Float\n"); break;
            case KW_BOOL: printf("Bool\n"); break;
            case KW_IF: printf("If\n"); break;
            case KW_THEN: printf("Then\n"); break;
            case KW_ELSE: printf("Else\n"); break;
            case KW_WHILE: printf("While\n"); break;
            case KW_LOOP: printf("Loop\n"); break;
            case KW_READ: printf("Read\n"); break;
            case KW_PRINT: printf("Print\n"); break;
            case KW_RETURN: printf("Return\n"); break;
            case OPERATOR_LE: printf("OPERATOR_LE\n"); break;
            case OPERATOR_GE: printf("OPERATOR_GE\n"); break;
            case OPERATOR_EQ: printf("OPERATOR_EQ\n"); break;
            case OPERATOR_DIF: printf("OPERATOR_DIF\n"); break;
            case TK_IDENTIFIER: printf("TK_IDENTIFIER\n"); break;
            case LIT_INTEGER: printf("LIT_INTEGER\n"); break;
            case LIT_FLOAT: printf("LIT_FLOAT\n"); break;
            case LIT_TRUE: printf("LIT_TRUE\n"); break;
            case LIT_FALSE: printf("LIT_FALSE\n"); break;
            case LIT_CHAR: printf("LIT_CHAR\n"); break;
            case LIT_STRING: printf("LIT_STRING\n"); break;
            case TOKEN_ERROR: printf("TOKEN_ERROR\n"); break;
            default: printf("ERROR\n"); break;
        }

        ++i;
    }
}