%{
	#include "structure.h"
	void yyerror(char *s);
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
	char* label;
	char* type_var;
	struct _symbole *symbole;
	struct _arbre *arbre;
}

%token <label> IDENTIFICATEUR
%token <label> CONSTANTE
%type <label> binary_op
%type <type_var> type 
%type <symbole> declarateur   
%type <symbole> liste_declarateurs
%type <symbole> liste_declarations
%type <symbole> declaration
%type <arbre> expression
%type <arbre> variable


%%
programme:
		liste_declarations liste_fonctions		{
													//printf("%s %s %s %s %s %s", $1->type_t, $1->var_t, $1->suivant_t->type_t, $1->suivant_t->var_t, $1->suivant_t->suivant_t->type_t, $1->suivant_t->suivant_t->var_t); 
												}
;

liste_declarations:
		liste_declarations declaration 			{
													$$ = ajouter($1, $2);
												}
	|											{ $$ = NULL; }
;

liste_fonctions:
		liste_fonctions fonction				{}
|       fonction								{}
;

declaration:	
		type liste_declarateurs ';'				{ $$ = fixer_type($2,$1);}
;


liste_declarateurs:	
		liste_declarateurs ',' declarateur		{ 		
													$$ = ajouter($1, $3);
												}
	|	declarateur								{ $$ = $1; }
;

declarateur:	
		IDENTIFICATEUR							{ $$ = (symbole*) malloc(sizeof(char*)*4); $$->var_t=$1; }
	|	declarateur '[' CONSTANTE ']'
;

fonction:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' { /*printf("Extern ");*/ }
;

type:	
		VOID						{ $$ = "VOID";}	
	|	INT							{ $$ = "INT"; }
;

liste_parms:	
		liste_parms ',' parm		{ }
	|	parm						{ }
	| 								{ }
;

parm:	
		INT IDENTIFICATEUR			{ }
	|								{ }
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
	|	RETURN expression ';'						{ }
;

affectation:	
		variable '=' expression						{ 
														affichage_arbre($3);
													/*	printf("%s = %s %s %s %s %s\n"
														, $1->label, $3->fils_t->label, $3->label, $3->fils_t->frere_t->label
														, $3->);*/
														
														//$1->label, $3->fils_t->label, $3->label, $3->fils_t->frere_t->label);
													}
;

bloc:	
		'{' liste_declarations liste_instructions '}'
;

appel:	
			IDENTIFICATEUR '(' liste_expressions ')' ';'	{ }	
;

variable:	
		IDENTIFICATEUR								{ $$ = creer_arbre($1, NULL, NULL); }
	|	variable '[' expression ']'					{}
;

expression:	
		'(' expression ')'							{ 
														$$ = $2;
													}
	|	expression binary_op expression %prec OP	{ 
														ajouter_frere($1,$3);
														$$ = creer_arbre($2,$1,NULL);
													}
	|	MOINS expression							{ 
														$$ = creer_arbre("-", $2, NULL);
													}
	|	CONSTANTE									{ 
														$$ = creer_arbre($1,NULL,NULL);
													}
	|	variable									{ $$ = $1; }
	|	IDENTIFICATEUR '(' liste_expressions ')'	{ /*printf("%s", $1);*/ }
	
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
	// nouvel=creer_arbre("a", creer_arbre("b",creer_arbre("e",NULL ,creer_arbre("f", creer_arbre("g",NULL ,NULL), NULL)) ,creer_arbre("c",NULL ,creer_arbre("d", NULL, NULL))), NULL);
	//affichage_arbre(nouvel);
	
	//init_table();
	yyparse();
	//creation_dot();
	return 0;
}