%{
    // Aluno: Gabriel Lando
    #include "y.tab.h"
    #include "hash.h"

    char *s;
    char buffer[STRING_SIZE];

    int Running = 1;
    int lineNumber = 1;
%}

%x COMMENT
%x STRING

%%

"char"                           return KW_CHAR;
"int"                            return KW_INT;
"float"                          return KW_FLOAT;
"bool"                           return KW_BOOL;

"if"                             return KW_IF;
"then"                           return KW_THEN;
"else"                           return KW_ELSE;
"while"                          return KW_WHILE;
"loop"                           return KW_LOOP;
"read"                           return KW_READ;
"print"                          return KW_PRINT;
"return"                         return KW_RETURN;

[,;:()\[\]{}\+-/<>=|^~&$#]       return yytext[0];

"<="                             return OPERATOR_LE;
">="                             return OPERATOR_GE;
"=="                             return OPERATOR_EQ;
"!="                             return OPERATOR_DIF;

"TRUE"                           hashInsert(yytext, LIT_TRUE); return LIT_TRUE;
"FALSE"                          hashInsert(yytext, LIT_FALSE); return LIT_FALSE;

[0-9A-F]+                        hashInsert(yytext, LIT_INTEGER); return LIT_INTEGER;
([0-9]([0-9A-F])*)*\.[0-9A-F]+   hashInsert(yytext, LIT_FLOAT); return LIT_FLOAT;

\"      BEGIN(STRING); s = buffer;

\'.\'   {   yytext[0] = yytext[1]; 
            yytext[1] = '\0';
            hashInsert(yytext, LIT_CHAR);
            return LIT_CHAR;
        }

[a-zA-Z][0-9a-zA-Z@_]*           hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;

[ \t]
"\n"                             ++lineNumber;
"//".*
"/*"                             BEGIN(COMMENT);
.                                return TOKEN_ERROR;

<COMMENT>.
<COMMENT>"\n"   ++lineNumber;
<COMMENT>"*/"   BEGIN(INITIAL);

<STRING>\\n     *s++ = '\n';
<STRING>\\\"    *s++ = '\"';
<STRING>\"      {	*s = 0;
                    BEGIN(INITIAL);
                    yytext = buffer;
                    hashInsert(yytext, LIT_STRING);
                    return LIT_STRING;
                }
<STRING>.       *s++ = *yytext;

%%

#include "y.tab.c"
#include "main.c"

int yywrap() {
    Running = 0;
    return 1;
}

int isRunning() {
    return Running;
}

void initMe() {
    Running = 1;
    lineNumber = 1;
    hashInit();
}

int getLineNumber() {
    return lineNumber;
}