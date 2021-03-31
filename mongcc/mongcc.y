%{
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	void yyerror(char *s);
	
%}

%token <name> IDENTIFICATEUR
%token <entier> CONSTANTE

%token VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme

%union {
	char* name;
	int entier;
}

%%
programme	:	
		liste_declarations liste_fonctions		{}
;
liste_declarations	:	
		liste_declarations declaration 			{}
	|											{}
;	
liste_fonctions	:	
		liste_fonctions fonction				{}
|               fonction						{}
;
declaration	:	
		type liste_declarateurs ';'				{}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur		{}
	|	declarateur								{}
;
declarateur	:	
		IDENTIFICATEUR							{printf("%s\n", $1);}
	|	declarateur '[' CONSTANTE ']'
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' { printf("Extern "); }
;
type	:	
		VOID						{ printf("de type VOID "); }	
	|	INT							{ printf("de type INT "); }
;
liste_parms	:	
		liste_parms ',' parm		{ printf("liste param "); }
	|	parm						{ printf("un param "); }
	| 								{printf("rien ");}
;
parm	:	
		INT IDENTIFICATEUR			{ printf("%s ", $2); }
	|								{ printf("aucun param "); }
;
liste_instructions :	
		liste_instructions instruction
	|
;
instruction	:	
		iteration
	|	selection
	|	saut
	|	affectation ';'
	|	bloc
	|	appel
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction
	|	WHILE '(' condition ')' instruction
;
selection	:	
		IF '(' condition ')' instruction %prec THEN
	|	IF '(' condition ')' instruction ELSE instruction
	|	SWITCH '(' expression ')' instruction
	|	CASE CONSTANTE ':' instruction
	|	DEFAULT ':' instruction
;
saut	:	
		BREAK ';'
	|	RETURN ';'									
	|	RETURN expression ';'						{ printf("return\n"); }
;
affectation	:	
		variable '=' expression						{ printf("\n");}
;
bloc	:	
		'{' liste_declarations liste_instructions '}'
;
appel	:	
			IDENTIFICATEUR '(' liste_expressions ')' ';'	{ printf("appel function %s \n", $1); }	
;
retour_appel :
		IDENTIFICATEUR '(' liste_expressions ')'		{ printf("utilisation function %s ", $1); }
;
variable	:	
		IDENTIFICATEUR								{ printf("variable %s ", $1); }
	|	variable '[' expression ']'
;
expression	:	
		'(' expression ')'
	|	expression binary_op expression %prec OP
	|	MOINS expression							{ printf("- ");}
	|	CONSTANTE									{ printf("vaut %d ",$1); }
	|	variable
	|	IDENTIFICATEUR '(' liste_expressions ')'
	| 	retour_appel
;
liste_expressions	:	
		liste_expressions ',' expression
	|	expression
	| 
;
condition	:	
		NOT '(' condition ')'
	|	condition binary_rel condition %prec REL
	|	'(' condition ')'
	|	expression binary_comp expression
;
binary_op	:	
		PLUS										{ printf(" + "); }
	|   MOINS										{ printf(" - "); }
	|	MUL											{ printf(" * "); }
	|	DIV											{ printf(" / "); }
	|   LSHIFT										{ printf(" << "); }
	|   RSHIFT										{ printf(" >> "); }
	|	LAND											{ printf(" && "); }
	|	LOR											{ printf(" || "); }
	|	BAND										{}
	|	BOR											{}
;
binary_rel	:	
		LAND
	|	LOR
;
binary_comp	:	
		LT
	|	GT
	|	GEQ
	|	LEQ
	|	EQ
	|	NEQ
;

%%

void yyerror(char *s)
{
	fprintf( stderr, "%s\n", s );
}

int main()
{
	//init_table();
	yyparse();
	//creation_dot();
	//TD6 MOTHER FUCKER BITCH LOOK AT THE TD6 !!!!!!!!
	return 0;
}