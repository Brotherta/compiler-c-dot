D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]                     
SEP                     [ \t\v\n\f]
%{
#include <stdio.h>
#include "y.tab.h"

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

{L}({L}|{D})*           { yylval.name = strdup(yytext); return ID; }  // Variables
{D}+                    { yylval.entier = atoi(yytext); return CONST; }  // 
"/*"({L}|{SEP}|{D})*"*/" {}


">>"                    { return RSHIFT; }
"<<"                    { return LSHIFT; }
"&&"                    { return AND; }
"||"                    { return OR; }
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
.                       { return OTHER; }
%%

