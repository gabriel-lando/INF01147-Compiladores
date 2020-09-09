// Aluno: Gabriel Lando

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yylex();
void initMe();
extern char * yytext;
extern FILE * yyin;

int isRunning(void);

int main(int argc, char ** argv) {
    int token = 0;
    fprintf(stderr, "Rodando main que nao eh do prof na etapa 2.\n\n");

    if (argc < 2) {
        printf("call: ./etapa2 input.txt\n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1], "r"))) {
        printf("Cannot open file %s... \n", argv[1]);
        exit(1);
    }

    initMe();
    yyparse();
    hashPrint();

    fprintf(stderr, "\nSuper! Compilation successful!\n");

    exit(0);
}