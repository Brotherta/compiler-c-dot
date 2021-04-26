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
	char* name;
	char* op;
	char* type_var;
	int entier;
	struct _symbole *symbole;
}

%token <name> IDENTIFICATEUR
%token <entier> CONSTANTE
%type <op> binary_op 
%type <type_var> type
%type <symbole> declarateur
%type <symbole> liste_declarateurs
%type <symbole> declaration
%type <symbole> liste_declarations

%%
programme:
		liste_declarations liste_fonctions		{
													printf("%s %s %s %s %s %s", $1->type_t, $1->var_t, $1->suivant_t->type_t, $1->suivant_t->var_t, $1->suivant_t->suivant_t->type_t, $1->suivant_t->suivant_t->var_t); 
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
														/*printf(" _%s %s %s %s %s_ ", 
																$3->expr1_t->expr1_t->node,
																$3->expr1_t->node, 
																$3->expr1_t->expr2_t->node,
																$3->node, 
																$3->expr2_t->node);*/
													}
;

bloc:	
		'{' liste_declarations liste_instructions '}'
;

appel:	
			IDENTIFICATEUR '(' liste_expressions ')' ';'	{ }	
;

variable:	
		IDENTIFICATEUR								{ /*printf("variable %s ", $1);*/ }
	|	variable '[' expression ']'
;

expression:	
		'(' expression ')'							{ 
														/*/*$$ = $2;*/
													}
	|	expression binary_op expression %prec OP	{ 
														/*$$ = (expression*) malloc(sizeof(char*));
														$$->node = $2;
														$$->expr1_t = $1;
														$$->expr2_t = $3;*/
													}
	|	MOINS expression							{ 
														/*$$ = (expression*) malloc(sizeof(char*));
														$$->node = "-";
														$$->expr2_t = $2;*/
													}
	|	CONSTANTE									{ 
														/*$$ = (expression*) malloc(sizeof(char*));
														char *tmp = (char*) malloc(sizeof(char*));
														sprintf(tmp,"%d",$1);
														$$->node=tmp;*/
													}
	|	variable									{  }
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
	//init_table();
	
	yyparse();
	//creation_dot();
	return 0;
}