%{
    #include <stdio.h>
%}
CONST [0-9]+
VAR [A-Za-z][a-zA-Z0-9_]*
DIMENSION "["{VAR}"]"|"["{CONST}"]"
TAB {VAR}[\ ]*{DIMENSION}
C_one_liner "//"[-a-zA-Z0-9!"#$%&'()*+,./:;<>?@\[\]\\^_`{|}~ \t]*\n
%%
"extern"
"int " {printf("INT");} // return int
"void"
"for"
"while"
"if"
"then"
"else"
"switch"
"case"
"default"
"break"
{C_one_liner} {printf("comment");}
{VAR}   {printf("VAR");} // return VAR
{TAB}  {printf("TAB") ;}
%%

int main()
{
    yylex();
    return (0);
    // ./exe1 > test
    // ./exe1 < test
}