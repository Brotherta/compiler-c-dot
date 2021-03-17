D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]                     
SEP                     [ \t\v\n\f]
%{
#include <stdio.h>
// #include "y.tab.h"

%}


%%
"extern"                { printf("EXTERN "); }  // mot reservé //
"int"                   { printf("INT "); }  // return int
"void"                  { printf("VOID "); }
"for"                   { printf("FOR "); }
"while"                 { printf("WHILE "); }
"if"                    { printf("IF "); }
"else"                  { printf("ELSE "); }
"switch"                { printf("SWITCH "); }
"case"                  { printf("CASE "); }
"default"               { printf("DEFAULT "); }
"break"                 { printf("BREAK "); }
"return"                { printf("RETURN "); }                      // mot reservé  \\ 

{L}({L}|{D})*           { printf("ID "); }  // Variables
{D}+                    { printf("CONST "); }  // 
"/*"({L}|{SEP}|{D})*"*/" { printf("COM "); }

L?'(\\|.[^\\'])+'       { printf("TAB "); }
L?\"(\\.|[^\\"])*\"     { printf("TAB "); }


">>"                    { printf("RSHIFT "); }
"<<"                    { printf("LSHIFT "); }
"&&"                    { printf("BAND "); }
"||"                    { printf("LOR "); }
"<="                    { printf("LEQ "); }
">="                    { printf("GEQ "); }
">"                     { printf("GT "); }
"<"                     { printf("LT "); }
"=="                    { printf("EQ "); }
"!="                    { printf("NEQ "); }
"="                     { printf("AFFECT "); }
"!"                     { printf("NOT "); }
"{"                     { printf("DEB_BLOCK "); }
"}"                     { printf("FIN_BLOCK "); }
";"                     { printf("EOI "); }
"("                     { printf("LPRT "); }
")"                     { printf("RPRT "); }
"["                     { printf("LCRT "); }
"]"                     { printf("RCRT ");}
"+"                     { printf("PLUS ");}
"*"                     { printf("MUL ");}
"-"                     { printf("MOINS ");}
"/"                     { printf("DIV ");}
","                     { printf("VIRG ");}
":"                     { printf("DP ");}
{SEP}+                  { printf("SEP "); }
.                       { printf("OTHER "); }
%%

int main()
{
    yylex();
    return 0;
}