%{
	extern int yylineno;
	#include "src/dot/dot_builder.h"
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
	char *type_t;
	struct _symbole *symbole;
	struct _arbre *arbre;
}
%token <label> IDENTIFICATEUR
%token <label> CONSTANTE


%type <label> binary_rel
%type <label> binary_comp


%type <type_t> type 

%type <arbre> programme

%type <arbre> expression expr_liste_creator liste_expressions
%type <arbre> variable
%type <arbre> tableau

%type <arbre> instruction liste_instructions inst_liste_creator
%type <arbre> saut
%type <arbre> iteration
%type <arbre> selection
%type <arbre> appel
%type <arbre> condition
%type <arbre> bloc 
%type <arbre> affectation

%type <arbre> fonction liste_fonctions liste_fonctions_creator
%type <arbre> case_default list_case_default

%type <symbole> parm liste_parms liste_parm_creator
%type <symbole> declarateur declaration liste_declarateurs liste_declarations


%%
programme:
	liste_declarations liste_fonctions {
		PROGRAMME = creer_arbre("programme", $2, NULL, MON_AUTRE);
		ajouter_symbole_arbre(PROGRAMME, TABLE[ACC]);
		creer_fichier_dot(PROGRAMME);
	}
;

liste_declarations:
	liste_declarations declaration {		
		TABLE[ACC]=ajouter_symbole(TABLE[ACC], $2);
	}

	| { nouvelle_adresse(); }
;

liste_fonctions:
	liste_fonctions_creator { $$=$1;}

	| { $$ = NULL; }
;

liste_fonctions_creator:
	liste_fonctions_creator fonction { ajouter_frere($1,$2); }

	| fonction { $$=$1;}
;

declaration:	
	type liste_declarateurs ';' { $$ = fixer_type($2,$1); }

	| EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' { 
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],creer_symbole_fonction($3, $2, $5));
	}
;

liste_declarateurs:	
	liste_declarateurs ',' declarateur { verif_redefinition($3->var_t ,$1);$$ = ajouter_symbole($1, $3); }

	| declarateur { $$ = $1; }
;

declarateur:	
	IDENTIFICATEUR { $$ = creer_symbole($1, NULL); }

	| declarateur '[' CONSTANTE ']' { incr_dimension($$); }
;

fonction:	
	type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {
		char* buf = malloc(256);
		snprintf(buf,256,"%s, %s",$2,$1);

		char* copy = malloc(256);
		strcpy(copy, buf);

		$$ = creer_arbre(copy, NULL, NULL, MON_FONCTION);

		ajouter_symbole(TABLE[ACC-1], TABLE[ACC]);
		ajouter_symbole_arbre($$, TABLE[ACC-1]);

		detruire_table_fonction();
		struct _arbre *bloc;
		TABLE[ACC] = ajouter_symbole(TABLE[ACC], creer_symbole_fonction($2, $1, $4));

		if (est_recursif) 
		{
			int nb_param_fonction = verif_fonction($2);
			if (nb_param_appel_recursif != nb_param_fonction) {
				char *buf = malloc(256);
				snprintf(buf,256, "%s n'a pas le bon nombre de parametre, %d au lieu de %d", $2, nb_param_appel_recursif, nb_param_fonction);
				char *copy=malloc(256);
				strcpy(copy,buf);
				free(buf);
				erreur(copy,NULL);
			}
			reset_la_recursion();
		}

		if ($8 == NULL) {
			bloc = creer_arbre("BLOC", NULL, NULL, MON_BLOC);
		} else {
			bloc = creer_arbre("BLOC", $8, NULL, MON_BLOC);
		}
		
		ajouter_fils($$, bloc);

		free(buf);
	}
;

type:	
	VOID { $$ = "VOID"; }	
	
	| INT { $$ = "INT"; }
;

parm :
	INT IDENTIFICATEUR { $$=creer_symbole($2,"INT"); }
;

liste_parms :
	liste_parm_creator {
		$$ = $1;
		nouvelle_adresse_param();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],$1);
	}
	| {
		$$ = NULL;
		nouvelle_adresse_param();
	}
;

liste_parm_creator :
	liste_parm_creator ',' parm { $$ = ajouter_symbole($1, $3); }

	| parm {/* rien */}
;

liste_instructions:	
	inst_liste_creator { $$ = $1; }
	
	| { $$=NULL; }
;

inst_liste_creator:
	inst_liste_creator instruction { ajouter_frere($1,$2); }
	
	| instruction { $$=$1;}
;

instruction:	
	iteration { $$ = $1; }

	| selection { $$ = $1; }

	| saut { $$ = $1; }

	| affectation ';' { $$ = $1; }

	| bloc { $$ = creer_arbre("BLOC", $1, NULL, MON_BLOC); }

	| appel { $$ = $1; }
;

iteration:
	FOR '(' affectation ';' condition ';' affectation ')' instruction {
		$$ = creer_arbre("FOR", $3, NULL, MON_ITERATION);
		ajouter_frere($3, $5);
		ajouter_frere($5, $7);
		ajouter_frere($7, $9);
	}

	| WHILE '(' condition ')' instruction {
		$$ = creer_arbre("WHILE",$3,NULL, MON_ITERATION);
		ajouter_frere($3,$5);
	}
;

selection:	
	IF '(' condition ')' instruction %prec THEN {
		$$ = creer_arbre("IF", $3, NULL, MON_IF);
		ajouter_frere($3, $5);
	}

	| IF '(' condition ')' instruction ELSE instruction {
		$$ = creer_arbre("IF", $3, NULL, MON_IF);
		ajouter_frere($3,$5);
		ajouter_frere($5,$7);
	}

	| SWITCH '(' expression ')' '{' list_case_default '}' {
		$$ = creer_arbre("SWITCH", $3, NULL, MON_SWITCH);
		verif_switch($6);
		ajouter_frere($3, $6);
	}
;

list_case_default :
	list_case_default case_default { ajouter_frere($1,$2); }

	| case_default { $$=$1; }
;

case_default:
	CASE CONSTANTE ':' liste_instructions {
		char *buf = malloc(256);
		snprintf(buf, 256, "CASE%s", $2);
		char* copy = malloc(256);
		strcpy(copy, buf);

		$$ = creer_arbre(copy, creer_arbre("BLOC",$4,NULL,MON_BLOC), NULL, MON_CASE);
		free(buf);
	}

	| DEFAULT ':' liste_instructions {
		$$ = creer_arbre("DEFAULT", creer_arbre("BLOC",$3,NULL,MON_BLOC), NULL, MON_DEFAUT);
	}
;

saut:	
	BREAK ';' { $$ = creer_arbre("BREAK", NULL, NULL, MON_BREAK); }

	| RETURN ';' { $$ = creer_arbre("RETURN",NULL,NULL, MON_RETURN); }

	| RETURN expression ';'{ $$ = creer_arbre("RETURN",$2,NULL,MON_RETURN); }
;

affectation:	
	variable '=' expression	{ 
		verif_type_affectation($1,$3);
		ajouter_frere($1, $3);
		$$ = creer_arbre(":=", $1, NULL, MON_AUTRE);
	}
;

bloc:	
	'{' liste_declarations liste_instructions '}' { 
		ajouter_symbole_arbre($$, TABLE[ACC]);										
		detruire_table();
		$$ = $3;
	}
;

appel:	
	IDENTIFICATEUR '(' liste_expressions ')' ';' { 
		int nb_param_fonction = verif_fonction($1);
		int nb_param_appel = verif_param_expression($3);
		if(nb_param_fonction == -1) // peut être un appel récursif.
		{
			set_la_recursion($1, nb_param_appel);
		} 
		else {
			if (nb_param_appel != nb_param_fonction) {
				char *buf = malloc(256);
				snprintf(buf,256, "%s n'a pas le bon nombre de parametre, %d au lieu de %d", $1, nb_param_appel, nb_param_fonction);
				char *copy=malloc(256);
				strcpy(copy,buf);
				free(buf);
				erreur(copy,NULL);
			}
		}
		$$=creer_arbre($1,$3,NULL,MON_APPEL);
	}	
;

variable:	
	IDENTIFICATEUR { $$ = creer_arbre($1, NULL, NULL, MON_VARIABLE); }

	| tableau { $$ = creer_arbre("TAB", $1, NULL, MON_TABLEAU); }
;

tableau:
	IDENTIFICATEUR { $$ = creer_arbre($1, NULL, NULL,MON_AUTRE); }

	| tableau '[' expression ']' { ajouter_frere($1,$3); }
;

expression:	
	'(' expression ')' { $$ = $2; }	

 	| expression PLUS expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre("+",$1,NULL,MON_AUTRE);
	}

	|expression MOINS expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre("-",$1,NULL,MON_AUTRE);
	}		

	| expression DIV expression	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("/",$1,NULL,MON_AUTRE);
	}	

	| expression MUL expression	{ 
		ajouter_frere($1,$3);
		$$ = creer_arbre("*",$1,NULL,MON_AUTRE);
	}

	| expression RSHIFT expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre(">>",$1,NULL,MON_AUTRE);
	}	

	| expression LSHIFT expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre("<<",$1,NULL,MON_AUTRE);
	}		

	| expression BAND expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre("&",$1,NULL,MON_AUTRE);
	}		

	| expression BOR expression { 
		ajouter_frere($1,$3);
		$$ = creer_arbre("|",$1,NULL,MON_AUTRE);
	}		

	| MOINS expression %prec MUL { 
		$$ = creer_arbre("-", $2, NULL,MON_AUTRE);
	}	

	| CONSTANTE { 
		$$ = creer_arbre($1,NULL,NULL,MON_AUTRE);
	}	

	| variable { 
		if (!strcmp("TAB", $1->label)) {
			rechercher_symbole($1->fils_t->label);
		} else {
			rechercher_symbole($1->label);	
		}
		$$ = $1; 
	}	

	| IDENTIFICATEUR '(' liste_expressions ')' { 
		int nb_param_fonction = verif_fonction($1);
		int nb_param_appel = verif_param_expression($3);

		if(nb_param_fonction == -1) // peut être un appel récursif.
		{
			set_la_recursion($1, nb_param_appel);
		} 
		else {
			if (nb_param_appel != nb_param_fonction) {
				char *buf = malloc(256);
				snprintf(buf,256, "%s n'a pas le bon nombre de parametre. %d au lieu de %d.", $1, nb_param_appel, nb_param_fonction);
				char *copy=malloc(256);
				strcpy(copy,buf);
				free(buf);
				erreur(copy,NULL);
			}
		}
		$$ = creer_arbre($1, $3,NULL,MON_APPEL);
	}
;

liste_expressions:	
	expr_liste_creator { $$ = $1; }

	| { $$ = NULL; }
;

expr_liste_creator:
	expr_liste_creator ',' expression { ajouter_frere($1,$3); }
	
	| expression { $$ = $1; }
;

condition:	
	NOT '(' condition ')' { $$ = creer_arbre("NOT", $3, NULL, MON_AUTRE); }

	| condition binary_rel condition %prec REL { $$ = creer_arbre($2, $1, $3, MON_AUTRE); }

	| '(' condition ')' { $$ = $2; }

	| expression binary_comp expression {
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



int main()
{
	reset_la_recursion();
	yyparse();
	return 0;
}