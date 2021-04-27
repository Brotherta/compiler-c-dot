D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]                     
SEP                     [ \t\v\n\f]
%{
#include <stdio.h>
#include "y.tab.h"
#include "structure.h"

%}


%%
"extern"                { return EXTERN; }  // mot reservé //
"int"                   { return INT; }  // return int
"void"                  { return VOID; }
"for"                   { return FOR; }
"while"                 { return WHILE; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"switch"                { return SWITCH; }
"case"                  { return CASE; }
"default"               { return DEFAULT; }
"break"                 { return BREAK; }
"return"                { return RETURN; }                      // mot reservé  \\ 

{L}({L}|{D})*           { yylval.label = strdup(yytext); return IDENTIFICATEUR; }  // Variables
{D}+                    { yylval.label = strdup(yytext); return CONSTANTE; }  // 
"/*"({L}|{SEP}|{D})*"*/" {}



">>"                    { return RSHIFT; }
"<<"                    { return LSHIFT; }
"&&"                    { return LAND; }
"&"                     { return BAND;}
"||"                    { return LOR; }
"|"                     { return BOR; }
"<="                    { return LEQ; }
">="                    { return GEQ; }
">"                     { return GT; }
"<"                     { return LT; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"="                     { return '='; }
"!"                     { return '!'; }
"{"                     { return '{'; }
"}"                     { return '}'; }
";"                     { return ';';}
"("                     { return '('; }
")"                     { return ')'; }
"["                     { return '['; }
"]"                     { return ']'; }
"+"                     { return PLUS; }
"*"                     { return MUL ; }
"-"                     { return MOINS; }
"/"                     { return DIV; }
","                     { return ','; }
":"                     { return ':'; }
{SEP}+                  {} // on fait rien
.                       { yyerror(strdup(yytext)); }
%%

