%{
    // Aluno: Gabriel Lando
    #include "lex.yy.h"

    int Running = 1;
    int LineNumber = 1;

    int isRunning(void) {
        return Running;
    }

    int getLineNumber(void) {
        return LineNumber;
    }
%}

%x COMMENT

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

"+"                              return OPERATOR_PLUS;
"-"                              return OPERATOR_MINUS;
"*"                              return OPERATOR_MULT;
"/"                              return OPERATOR_DIV;

"|"                              return OPERATOR_OR;                           
"^"                              return OPERATOR_AND;
"~"                              return OPERATOR_NOT;
"<"                              return OPERATOR_LT;
"<="                             return OPERATOR_LE;
">="                             return OPERATOR_GE;
"=="                             return OPERATOR_EQ;
"!="                             return OPERATOR_DIF;

[,|;|:|(|)|\[|\]|{|}|=|&|$|#]    return yytext[0];

"TRUE"                           { yylval.symbol = HashInsert(yytext, LIT_TRUE); return LIT_TRUE; }
"FALSE"                          { yylval.symbol = HashInsert(yytext, LIT_FALSE); return LIT_FALSE; }

'.'                              { yylval.symbol = HashInsert(yytext, LIT_CHAR); return LIT_CHAR; }
\"(\\.|[^"])*\"	                 { yylval.symbol = HashInsert(yytext, LIT_STRING); return LIT_STRING; }

[0-9A-F]+                        { yylval.symbol = HashInsert(yytext, LIT_INTEGER); return LIT_INTEGER; }
([0-9]([0-9A-F])*)*\.[0-9A-F]+   { yylval.symbol = HashInsert(yytext, LIT_FLOAT); return LIT_FLOAT; }

[a-zA-Z][0-9a-zA-Z@_]*           { yylval.symbol = HashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER; }

[ \t]
"\n"                             ++LineNumber;
"//".*
"/*"                             BEGIN(COMMENT);
.                                return TOKEN_ERROR;

<COMMENT>.
<COMMENT>"\n"   ++LineNumber;
<COMMENT>"*/"   BEGIN(INITIAL);

%%

#include "main.c"

int yywrap() {
    Running = 0;
    return 1;
}

void initMe() {
    Running = 1;
    LineNumber = 1;
    HashInit();
}