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
%type <type_var> type 
%type <symbole> declarateur   
%type <symbole> liste_declarateurs
%type <symbole> liste_declarations
%type <symbole> declaration
%type <arbre> expression
%type <arbre> variable


%%
programme:
		liste_declarations liste_fonctions		
		{

			//printf("%s %s %s %s %s %s", $1->type_t, $1->var_t, $1->suivant_t->type_t, $1->suivant_t->var_t, $1->suivant_t->suivant_t->type_t, $1->suivant_t->suivant_t->var_t); 
		}
;

liste_declarations:
		liste_declarations declaration 			
		{							
			TABLE[ACC] = ajouter_symbole(TABLE[ACC], $2);
		}
	|										
		{  
			nouvelle_adresse(); 
			//printf("nouvelle décl %d\n",ACC);
		}
;

liste_fonctions:
		liste_fonctions fonction				
		{
			
		}
	|	fonction								
		{
			
		}
;

declaration:	
		type liste_declarateurs ';'				
		{
			$$ = fixer_type($2,$1);
		}
;


liste_declarateurs:	
		liste_declarateurs ',' declarateur		
		{ 		
			$$ = ajouter_symbole($1, $3);
		}
	|	declarateur								
		{ 
			$$ = $1; 
		}
;

declarateur:	
		IDENTIFICATEUR							
		{ 
			$$ = (symbole*) malloc(sizeof(char*)*4); $$->var_t=$1; 
		}
	|	declarateur '[' CONSTANTE ']'
;

fonction:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' 	
		{ 
			detruire_table();
			//printf("sorti fonction : %d\n",ACC);
		}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 
		{ 
			
		}
;

type:	
		VOID						
		{ 
			$$ = "VOID";
		}	
	|	INT							
		{ 
			$$ = "INT"; 
		}
;

liste_parms:	
		liste_parms ',' parm		
		{ 

		}
	|	parm						
		{

		}
	| 								
		{ 

		}
;

parm:	
		INT IDENTIFICATEUR			
		{ 

		}
	|								
		{ 

		}
;

liste_instructions:	
		liste_instructions instruction
		{
			// TODO
		}
	|	
		{
			// TODO
		}
;

instruction:	
		iteration					
		{
			//
		}
	|	selection
		{
			// TODO
		}
	|	saut
		{
			// TODO
		}
	|	affectation ';'
		{
			// TODO
		}
	|	bloc
		{
			// TODO
		}
	|	appel
		{
			// TODO
		}
;

iteration:
		FOR '(' affectation ';' condition ';' affectation ')' instruction
		{
			// TODO
		}
	|	WHILE '(' condition ')' instruction
		{
			// TODO
		}
;

selection:	
		IF '(' condition ')' instruction %prec THEN
		{
			// TODO
		}
	|	IF '(' condition ')' instruction ELSE instruction
		{
			// TODO
		}
	|	SWITCH '(' expression ')' instruction
		{
			// TODO
		}
	|	CASE CONSTANTE ':' instruction
		{
			// TODO
		}
	|	DEFAULT ':' instruction
		{
			// TODO
		}
;

saut:	
		BREAK ';'
		{
			// TODO
		}
	|	RETURN ';'
		{
			// TODO
		}									
	|	RETURN expression ';'
		{
			// TODO
		}
;

affectation:	
		variable '=' expression						
		{ 
			rechercher_symbole($1->label);
			affichage_arbre($3);
		}
;

bloc:	
		'{' liste_declarations liste_instructions '}' 	
		{ 										
			detruire_table();
			//printf("sorti bloc : %d\n", ACC);
		}
;

appel:	
		IDENTIFICATEUR '(' liste_expressions ')' ';'	
		{ 
			
		}	
;

variable:	
		IDENTIFICATEUR								
		{
			 $$ = creer_arbre($1, NULL, NULL); 
		}
	|	variable '[' expression ']'					
		{

		}
;

expression:	
		'(' expression ')' 		 {$$ = $2;}			
 	|	expression PLUS expression 		
	 	{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("+",$1,NULL);
		}
	|	expression MOINS expression	
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("-",$1,NULL);
		}			
	|	expression DIV expression	
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("/",$1,NULL);
		}			
	|	expression MUL expression				
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("*",$1,NULL);
		}
	|	expression RSHIFT expression
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre(">>",$1,NULL);
		}				
	|	expression LSHIFT expression
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("<<",$1,NULL);
		}				
	|	expression BAND expression	
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("&",$1,NULL);
		}			
	|	expression BOR expression	
		{ 
			ajouter_frere($1,$3);
			$$ = creer_arbre("|",$1,NULL);
		}			
	|	MOINS expression %prec MUL	
		{ 
			$$ = creer_arbre("-", $2, NULL);
		}			
	|	CONSTANTE 	
		{ 
			$$ = creer_arbre($1,NULL,NULL);
		}				
	|	variable 	
		{ 
			$$ = $1; 
		}					
	|	IDENTIFICATEUR '(' liste_expressions ')' 
		{ 
			/*printf("%s", $1);*/ 
		}
;

liste_expressions:	
		liste_expressions ',' expression
		{
			// TODO
		}
	|	expression
		{
			// TODO
		}
	| 
		{
			// TODO
		}
;

condition:	
		NOT '(' condition ')'
		{
			// TODO
		}
	|	condition binary_rel condition %prec REL
		{
			// TODO
		}
	|	'(' condition ')'
		{
			// TODO
		}
	|	expression binary_comp expression
		{
			// TODO
		}
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