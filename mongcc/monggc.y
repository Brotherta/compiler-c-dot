%{
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	void yyerror(char *s);
%}

%token <name> ID
%token <entier> CONST

%token EXTERN INT VOID FOR WHILE IF ELSE SWITCH CASE DEFAULT BREAK RETURN
%token RSHIFT LSHIFT AND OR LEQ GEQ GT LT EQ NEQ AFFECT NOT DEB_BLOCK FIN_BLOCK PV COM 
%token OTHER DP VIRG DIV MOINS MUL PLUS LCRT RCRT LPRT RPRT 

%left PLUS MOINS MUL DIV LSHIFT RSHIFT
%left AND OR OP REL

%nonassoc ELSE

%start programme

%union {
	char* name;
	int entier;
}

%%
programme :	
		liste_declarations
;

liste_declarations :
		liste_declarations declaration
		| declaration
;

declaration :	
		INT ID AFFECT CONST PV			{ printf("La variable : %s vaut %d\n", $2, $4); }
;

%%
void yyerror(char *s)
{
	fprintf( stderr, "%s\n", s );
}
int main()
{
	yyparse();
	return 0;
}