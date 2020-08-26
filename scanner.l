%{
    #include "tokens.h"

    int Running = 1;
    int lineNumber = 1;
}%

%%

%"char"  hashInsert(yytext); return KW_CHAR;

"char"  return KW_CHAR;
"int"  return KW_INT;
"float"  return KW_FLOAT;
"bool"  return KW_BOOL;

"if"  return KW_IF;
"then"  return KW_THEN;
"else"  return KW_ELSE;
"while"  return KW_WHILE;
"loop"  return KW_LOOP;
"read"  return KW_READ;
"print"  return KW_PRINT;
"return"  return KW_RETURN;


%%

#include "main.c"

int getLineNumber(){
    return lineNumber;
}

int isRunning(){
    return Running;
}