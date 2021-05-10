D                       [0-9]
L                       [a-zA-Z_]                 
SEP                     [ \t\v\f]
INTERDIT                [²&é~"#'è`ç^à@°€$£¤¨µ%ù§.?■ÜÖ☺]

%{
#include "y.tab.h"
#include "structure.h"

%}

%option yylineno

%%
"extern"                { return EXTERN; }  
"int"                   { return INT; }  
"void"                  { return VOID; }
"for"                   { return FOR; }
"while"                 { return WHILE; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"switch"                { return SWITCH; }
"case"                  { return CASE; }
"default"               { return DEFAULT; }
"break"                 { return BREAK; }
"return"                { return RETURN; }                      

{L}({L}|{D})*           { yylval.label = strdup(yytext); return IDENTIFICATEUR; }  
{D}+                    { yylval.label = strdup(yytext); return CONSTANTE; }  
"/*"({L}|{SEP}|{INTERDIT}|{D})*"*/" {}
"//"({L}|{SEP}|{INTERDIT}|{D})*     {}



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
\n                      {}
{SEP}+                  {}
{INTERDIT}              { erreur("caractère interdit.",strdup(yytext)); }
.                       { }
%%

