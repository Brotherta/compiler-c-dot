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
		liste_declarations liste_fonctions			{}
;

liste_declarations :
		liste_declarations declaration				{}
		|											{}
;

declaration :	
		type liste_declarateurs ';'					{}
;

type : 
		VOID 										{ printf("de type VOID "); }
		| INT										{ printf("de type INT "); }
;

liste_declarateurs :
		liste_declarateurs ',' declarateur  		{}
		| declarateur								{}
;

declarateur :
		declarateur '[' CONST ']'					{}
		| ID										{ printf("%s\n", $1); }
;

liste_fonctions :
		liste_fonctions fonction					{}
		| fonction									{}
;

fonction :
		type variable '(' liste_parametres ')' '{' 
			liste_declarations liste_instructions 
		'}'											{}		
;

liste_parametres :
		liste_parametres ',' parametre				{ printf("liste param "); }
		| parametre									{ printf("un param "); }
;

parametre :
		INT ID										{ printf(" %s ", $2); }
		| 											{ printf(" aucun param"); }
;

liste_instructions :
		liste_instructions instruction				{}
		| 											{}
;

instruction :
	affectation										{}
;

affectation : 
		variable '=' expression	';'					{ printf("\n");}
;

variable :	
		ID											{ printf("variable %s", $1); }
;

expression :
		CONST 										{ printf("  vaut %d",$1); }
	|	variable									{}	
	| 	expression binary_op expression 			{}
;

binary_op	:	
		PLUS										{ printf(" + "); }
	|   MOINS										{ printf(" - "); }
	|	MUL											{ printf(" * "); }
	|	DIV											{ printf(" / "); }
	|   LSHIFT										{ printf(" << "); }
	|   RSHIFT										{ printf(" >> "); }
	|	AND											{ printf(" && "); }
	|	OR											{ printf(" || "); }
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