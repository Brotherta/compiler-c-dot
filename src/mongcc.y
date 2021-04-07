%{
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	#include "structure.h"
	void yyerror(char *s);

	typedef struct _expression {
		char* node;
		struct _expression *expr1;
		struct _expression *expr2;
	} expression;

%}



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
	char* op;
	char* type_var;
	int entier;
	struct _fonction *f_t;
	struct _expression *expr_t;
}

%token <name> IDENTIFICATEUR
%token <entier> CONSTANTE
%type <expr_t> expression
%type <op> binary_op 
%type <type_var> type

%%
programme:
		liste_declarations liste_fonctions		{}
;
liste_declarations:
		liste_declarations declaration 			{}
	|											{}
;	
liste_fonctions:
		liste_fonctions fonction				{}
|       fonction								{}
;
declaration:	
		type liste_declarateurs ';'				{}
;
liste_declarateurs:	
		liste_declarateurs ',' declarateur		{}
	|	declarateur								{}
;
declarateur:	
		IDENTIFICATEUR							{ printf("%s\n", $1); }
	|	declarateur '[' CONSTANTE ']'
;
fonction:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' { printf("Extern "); }
;
type:	
		VOID						{ $$ = "void"; }	
	|	INT							{ $$ = "int"; }
;
liste_parms:	
		liste_parms ',' parm		{ printf("liste param "); }
	|	parm						{ printf("un param "); }
	| 								{printf("rien ");}
;
parm:	
		INT IDENTIFICATEUR			{ printf("%s ", $2); }
	|								{ printf("aucun param "); }
;
liste_instructions:	
		liste_instructions instruction
	|
;
instruction:	
		iteration					
	|	selection					{/* stock a la suite de ma precedente instruction*/}
	|	saut
	|	affectation ';'
	|	bloc
	|	appel						{/* enum CALL*/}
;
iteration:
		FOR '(' affectation ';' condition ';' affectation ')' instruction
	|	WHILE '(' condition ')' instruction
;
selection:	
		IF '(' condition ')' instruction %prec THEN
	|	IF '(' condition ')' instruction ELSE instruction
	|	SWITCH '(' expression ')' instruction		{/* creer instruction switch*/}
	|	CASE CONSTANTE ':' instruction				{/* cree instruction case */}
	|	DEFAULT ':' instruction
;
saut:	
		BREAK ';'
	|	RETURN ';'									
	|	RETURN expression ';'						{ printf("return \n"); }
;
affectation:	
		expression '=' expression						{ 
															printf(" _%s %s %s %s %s_ ", 
																	$3->expr1->expr1->node,
																	$3->expr1->node, 
																	$3->expr1->expr2->node,
																	$3->node, 
																	$3->expr2->node);
														}
;
bloc:	
		'{' liste_declarations liste_instructions '}'
;
appel:	
			IDENTIFICATEUR '(' liste_expressions ')' ';'	{ printf("appel function %s \n", $1); }	
;
retour_appel:
		IDENTIFICATEUR '(' liste_expressions ')'		{ printf("utilisation function %s ", $1); }
;
variable:	
		IDENTIFICATEUR								{ printf("variable %s ", $1); }
	|	variable '[' expression ']'
;
expression:	
		'(' expression ')'							{ 
														$$ = $2;
													}
	|	expression binary_op expression %prec OP	{ 
														$$ = (expression*) malloc(sizeof(char*));
														$$->node = $2;
														$$->expr1 = $1;
														$$->expr2 = $3;
													}
	|	MOINS expression							{ 
														$$ = (expression*) malloc(sizeof(char*));
														$$->node = "-";
														$$->expr2 = $2;
													}
	|	CONSTANTE									{ 
														$$ = (expression*) malloc(sizeof(char*));
														char *tmp = (char*) malloc(sizeof(char*));
														sprintf(tmp,"%d",$1);
														$$->node=tmp;
													}
	|	variable									{  }
	|	IDENTIFICATEUR '(' liste_expressions ')'	{  }
	| 	retour_appel								{  }
; 

liste_expressions:	
		liste_expressions ',' expression
	|	expression
	| 
;
condition:	
		NOT '(' condition ')'
	|	condition binary_rel condition %prec REL
	|	'(' condition ')'
	|	expression binary_comp expression
;
binary_op:	
		PLUS										{ $$ = "+"; }
	|   MOINS										{ $$ = "-"; }
	|	MUL											{ $$ = "*"; }
	|	DIV											{ $$ = "/"; }
	|   LSHIFT										{ $$ = "<<"; }
	|   RSHIFT										{ $$ = ">>"; }
	|	LAND										{ $$ = "&&"; }
	|	LOR											{ $$ = "||"; }
	|	BAND										{ $$ = "&"; }
	|	BOR											{ $$ = "|"; }
;

binary_rel:	
		LAND
	|	LOR
;
binary_comp:	
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