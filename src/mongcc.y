%{
	#include "dot/dot_builder.h"
	//#include "structure.h"
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
%type <label> binary_rel
%type <label> binary_comp


%type <type_var> type 

%type <arbre> expression
%type <arbre> variable
%type <arbre> affectation
%type <arbre> bloc 
%type <arbre> instruction
%type <arbre> saut
%type <arbre> iteration
%type <arbre> selection
%type <arbre> appel
%type <arbre> liste_expressions
%type <arbre> expr_liste_creator
%type <arbre> condition
%type <arbre> liste_instructions
%type <arbre> inst_liste_creator
%type <arbre> fonction
%type <arbre> case_default
%type <arbre> list_case_default
%type <arbre> liste_fonctions
%type <arbre> liste_fonctions_creator
%type <arbre> programme
%type <arbre> tableau

%type <symbole> liste_parms
%type <symbole> parm
%type <symbole> liste_parm_creator
%type <symbole> declarateur   
%type <symbole> liste_declarateurs
%type <symbole> liste_declarations
%type <symbole> declaration

%%
programme:
	liste_declarations liste_fonctions		
	{
		PROGRAMME = creer_arbre("programme", $2, NULL, MON_AUTRE);
		//affichage_arbre(PROGRAMME);
		creer_fichier_dot(PROGRAMME);
		//generer_dot($$);
	}
;
liste_declarations:
	liste_declarations declaration 			
	{			
		TABLE[ACC]=ajouter_symbole(TABLE[ACC], $2);
		struct _symbole *tmp = TABLE[ACC];	
	}
	|										
	{  
		nouvelle_adresse(); 
		//printf("nouvelle décl %d\n",ACC);
	}
;

liste_fonctions:
	liste_fonctions_creator 				
	{
		$$=$1;
	}
	|							
	{
		
	}
;
liste_fonctions_creator:
	liste_fonctions_creator fonction
	{
		ajouter_frere($1,$2);
	}
	| fonction
	{
		$$=$1;
	}
;
declaration:	
	type liste_declarateurs ';'				
	{
		$$ = fixer_type($2,$1);
	}
	| EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 
	{ 
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],creer_symbole($3, $2));
	}
;
liste_declarateurs:	
	liste_declarateurs ',' declarateur		
	{ 		
		$$ = ajouter_symbole($1, $3);
		
	}
	| declarateur								
	{ 
		$$ = $1; 
	}
;
declarateur:	
	IDENTIFICATEUR							
	{ 
		$$ = creer_symbole($1, NULL);  
	}
	| declarateur '[' CONSTANTE ']'
	{
		
	}
;
fonction:	
	type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' 	
	{
		detruire_table_fonction();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],creer_symbole($2, $1));
		struct _arbre *bloc = creer_arbre("BLOC", $8, NULL, MON_BLOC);

		char* buf = malloc(256);
		snprintf(buf,256,"%s, %s",$2,$1);

		char* copy = malloc(256);
		strcpy(copy, buf);

		$$ = creer_arbre(copy, bloc, NULL, MON_FONCTION);
		free(buf);
	}
;
type:	
	VOID						
	{ 
		$$ = "VOID";
	}	
	| INT							
	{ 
		$$ = "INT"; 
	}
;
parm :
	INT IDENTIFICATEUR
	{
		$$=creer_symbole($2,"INT");
	}
;
liste_parms :
	liste_parm_creator
	{
		nouvelle_adresse();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],$1);
	}
	| 
	{
		nouvelle_adresse();
	}
;
liste_parm_creator :
	liste_parm_creator ',' parm
	{
		$$ = ajouter_symbole($1, $3);
		
	}
	| parm
	{
		
	}
;
liste_instructions:	
	inst_liste_creator
	{
		$$ = $1;
	}
	|	
	{
	
	}
;
inst_liste_creator:
	inst_liste_creator instruction
	{
		ajouter_frere($1,$2);
	}
	| instruction
	{
		$$=$1;
	}
;
instruction:	
	iteration					
	{
		$$ = $1;
	}
	| selection
	{
		$$ = $1;
	}
	| saut
	{
		$$ = $1;
	}
	| affectation ';'
	{
		$$ = $1;
	}
	| bloc
	{
		$$ = creer_arbre("BLOC", $1, NULL, MON_BLOC);
	}
	| appel
	{
		$$ = $1;
	}
;
iteration:
	FOR '(' affectation ';' condition ';' affectation ')' instruction
	{
		$$ = creer_arbre("FOR", $3, NULL, MON_ITERATION);
		ajouter_frere($3, $5);
		ajouter_frere($5, $7);
		ajouter_frere($7, $9);
	}
	| WHILE '(' condition ')' instruction
	{
		$$ = creer_arbre("WHILE",$3,NULL, MON_ITERATION);
		ajouter_frere($3,$5);
	}
;
selection:	
	IF '(' condition ')' instruction %prec THEN
	{
		$$ = creer_arbre("IF", $3, NULL, MON_IF);
		ajouter_frere($3, $5);
	}
	| IF '(' condition ')' instruction ELSE instruction
	{
		$$ = creer_arbre("IF", $3, NULL, MON_IF);
		ajouter_frere($3,$5);
		ajouter_frere($5,$7);
	}
	| SWITCH '(' expression ')' '{' list_case_default '}'
	{
		$$ = creer_arbre("SWITCH", $3, NULL, MON_SWITCH);
		ajouter_frere($3, $6);
	}
;

list_case_default :
	list_case_default case_default
	{
		ajouter_frere($1,$2);
	}
	| case_default
	{
		$$=$1;
	}
;
case_default:
	| CASE CONSTANTE ':' liste_instructions
	{
		$$ = creer_arbre("CASE", creer_arbre($2,NULL,$4, MON_AUTRE), NULL, MON_CASE);
	}
	| DEFAULT ':' liste_instructions
	{
		$$ = creer_arbre("DEFAULT", $3, NULL, MON_DEFAUT);
	}
;

saut:	
	BREAK ';'
	{
		$$ = creer_arbre("BREAK", NULL, NULL, MON_BREAK);
	}
	| RETURN ';'
	{
		$$ = creer_arbre("RETURN",NULL,NULL, MON_RETURN);
	}									
	| RETURN expression ';'
	{
		$$ = creer_arbre("RETURN",$2,NULL,MON_RETURN);
	}
;

affectation:	
	variable '=' expression						
	{ 
		rechercher_symbole($1->label);
		ajouter_frere($1, $3);
		$$ = creer_arbre(":=", $1, NULL,MON_AUTRE);
	}
;

bloc:	
	'{' liste_declarations liste_instructions '}' 	
	{ 										
		detruire_table();
		$$ = $3;
	}
;
appel:	
	IDENTIFICATEUR '(' liste_expressions ')' ';'	
	{ 
		$$=creer_arbre($1,$3,NULL,MON_APPEL);
	}	
;
variable:	
	IDENTIFICATEUR								
	{
		$$ = creer_arbre($1, NULL, NULL,MON_AUTRE); 
	}
	| tableau
	{
		$$ = creer_arbre("TAB", $1, NULL, MON_TABLEAU);
	}
;

tableau:
	IDENTIFICATEUR							
	{
		$$ = creer_arbre($1, NULL, NULL,MON_AUTRE); 
	}
	| tableau '[' expression ']' 					
	{
		ajouter_frere($1,$3);
	}
;
expression:	
	'(' expression ')' 		 
	{
		$$ = $2;
	}			
 	| expression PLUS expression 		
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("+",$1,NULL,MON_AUTRE);
	}
	|expression MOINS expression	
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("-",$1,NULL,MON_AUTRE);
	}			
	| expression DIV expression	
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("/",$1,NULL,MON_AUTRE);
	}			
	| expression MUL expression				
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("*",$1,NULL,MON_AUTRE);
	}
	| expression RSHIFT expression
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre(">>",$1,NULL,MON_AUTRE);
	}				
	| expression LSHIFT expression
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("<<",$1,NULL,MON_AUTRE);
	}				
	| expression BAND expression	
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("&",$1,NULL,MON_AUTRE);
	}			
	| expression BOR expression	
	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("|",$1,NULL,MON_AUTRE);
	}			
	| MOINS expression %prec MUL	
	{ 
		$$ = creer_arbre("-", $2, NULL,MON_AUTRE);
	}			
	| CONSTANTE 	
	{ 
		$$ = creer_arbre($1,NULL,NULL,MON_AUTRE);
	}				
	| variable 	
	{ 
		$$ = $1; 
	}					
	| IDENTIFICATEUR '(' liste_expressions ')' 
	{ 
		$$ = creer_arbre($1, $3,NULL,MON_APPEL);
	}
;
liste_expressions:	
	expr_liste_creator
	{
		$$ = $1;
	}
	| {/* rien */}
;
expr_liste_creator:
	expr_liste_creator ',' expression
	{
		ajouter_frere($1,$3);
	}
	| expression
	{
		$$ = $1;
	}
;
condition:	
	NOT '(' condition ')'
	{
		$$ = creer_arbre("NOT", $3, NULL, MON_AUTRE);
	}
	| condition binary_rel condition %prec REL
	{
		$$ = creer_arbre($2, $1, $3, MON_AUTRE);
	}
	| '(' condition ')'
	{
		$$ = $2;
	}
	| expression binary_comp expression
	{
		ajouter_frere($1,$3);
		$$ = creer_arbre($2, $1,NULL, MON_AUTRE);
	}
;
binary_rel:	
		LAND { $$ = "&&"; }
	|	LOR  { $$ = "||"; }
;
binary_comp:	
		LT { $$ = "<"; }
	|	GT { $$ = ">"; }
	|	GEQ { $$ = ">=";}
	|	LEQ { $$ = "<=";}
	|	EQ { $$ = "==";}
	|	NEQ { $$ = "!=";}
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