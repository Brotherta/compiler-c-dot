#include "structure.h"
extern int yylineno;

int ACC = 0;
char *label_appel_recursif;
int est_recursif = 0;
int nb_param_appel_recursif = 0;


void reset_la_recursion()
{
    label_appel_recursif = NULL;
    est_recursif = 0;
    nb_param_appel_recursif = 0;
}

void set_la_recursion(char* label, int nb_param_appel) {

    label_appel_recursif = label;
	est_recursif = 1;
	nb_param_appel_recursif = nb_param_appel;
}

void nouvelle_adresse()
{
    while (TABLE[ACC] != NULL) 
    {
        ACC++;
    }
}

void nouvelle_adresse_param() 
{
    ACC++;
}

void detruire_table()
{
    if (ACC > 0) {
        TABLE[ACC] = NULL;
        ACC--;
    }
}

void detruire_table_fonction() { //sortir_table_fonction
    detruire_table(); // sortie du bloc de la fonction
    detruire_table(); // sortie de la fonction
}

arbre *creer_arbre(char *label, arbre *fils, arbre *frere, enum type_arbre typeEnum)
{
    struct _arbre *nouvel_arbre = (arbre*) malloc(sizeof(arbre));
    nouvel_arbre->type_arbre_t = typeEnum; 
    nouvel_arbre->label=label;
    nouvel_arbre->frere_t=frere;
    nouvel_arbre->fils_t=fils;
    return nouvel_arbre;
}

// on ajoute le premier fils a l'arbre actuel
void *ajouter_fils(arbre *actuel, arbre *fils) {
    actuel->fils_t = fils;
}

//On n'ajoute pas la liste des fils, mais on ajoute au premier fils, la liste de ses freres ( le 4éme frere est donc frere du 3éme, le 1er ne connais que le 2éme)
void *ajouter_frere(arbre *actuel, arbre *frere) {
    struct _arbre *frere_courant = actuel;
    while(frere_courant->frere_t != NULL) { // tant qu'on trouve des freres on continue de les parcourirs
        frere_courant = frere_courant->frere_t;
    }
    frere_courant->frere_t = frere; // On viens de trouver un frere sans aucun frere, on lui rajoute donc son frere
}

symbole *creer_symbole(char* var_t, char* type_t) {
    verif_redefinition(var_t, TABLE[ACC]);
    struct _symbole *nouveau_symbole = (symbole*) malloc(sizeof(symbole));
    nouveau_symbole->var_t = var_t;   // le nom du symbole
    nouveau_symbole->type_t = type_t; // "INT" ou "VOID"
    nouveau_symbole->dimension = 0;   //La dimensions permet de vérifié s'il s'agit d'un tableau, 0 indique un int simple, x>0 indique un tableau a x dimensions
    nouveau_symbole->nb_param = -1;   // le nb_param permet de vérifié s'il s'agit d'une fonction , -1 indique une variable, x>=0 indique une fonction a x parametre
                                    // On met le nb_param a -1 car creer_symbole ne sert que pour des variables, il doit toutefois avoir une valeur, on a choisi -1
    return nouveau_symbole;
}

symbole *creer_symbole_fonction(char* var_t, char* type_t, symbole *liste_param)
{
    struct _symbole *actuel = creer_symbole(var_t,type_t); 
    struct _param *param_courant = (param*) malloc(sizeof(param));
    actuel->nb_param = 0;
    actuel->param_t = param_courant;
    while(liste_param != NULL) 
    {
        actuel->nb_param++;
        param_courant->type_t = liste_param->type_t;
        struct _param *nouveau_param = (param*) malloc(sizeof(param));
        param_courant->suivant_t = nouveau_param;
        liste_param = liste_param->suivant_t;
        param_courant = param_courant->suivant_t;
    }
    return actuel;
}

void verif_redefinition(char* label, symbole *table_actuel) {
    struct _symbole *courant = table_actuel;
    while(courant != NULL) {
        if (!strcmp(courant->var_t,label)) {
            erreur("la variable est déjà défini", label);
        }
        courant=courant->suivant_t;
    }
}

void incr_dimension(symbole *actuel){
    actuel->dimension++;
}

symbole *ajouter_symbole(symbole *actuel, symbole *futur) {
    if (actuel == NULL) {
        return futur; // correspond a créé une table de symbole a partir de rien et d'un suivant
    }
    struct _symbole *courant = actuel;
    while(courant->suivant_t != NULL)
    {
        courant = courant->suivant_t;
    }
    courant->suivant_t = futur; 
    return actuel;
}

symbole *fixer_type(symbole *actuel, char* type_t)
{
    struct _symbole *courant = actuel;

    while(courant->suivant_t != NULL)
    {
        courant->type_t = type_t;
        courant = courant->suivant_t;
    }

    courant->type_t = type_t;
    return actuel;
}

int rechercher_symbole(char *label)
{
    int ACC_copie = ACC;
    while(ACC_copie >= 0) {
        struct _symbole *courant = TABLE[ACC_copie];
        while(courant != NULL) {
            if (!strcmp(courant->var_t,label)) {
                return courant->dimension;
            }
            courant=courant->suivant_t;
        }
        ACC_copie--;
    }
    erreur("n'est pas défini", label);
}

void verif_type_affectation(arbre *variable, arbre *expression) {
    int dimension_symbole;

    // On récupère la dimension du symbole de la variable et on vérifie le type de la variable.
    if (variable->type_arbre_t == MON_TABLEAU && variable->fils_t != NULL) {
        dimension_symbole = rechercher_symbole(variable->fils_t->label);
    }
    else {
        dimension_symbole = rechercher_symbole(variable->label);
    }
    int dimension_variable = get_dimension_variable(dimension_symbole, variable);
    verif_dimension_expression(dimension_variable, expression);
}

int get_dimension_variable(int dimension_max, arbre *actuel) {
    struct _arbre *liste_frere = NULL;
    if(actuel->fils_t != NULL)
    {
        liste_frere=actuel->fils_t->frere_t;
        while(liste_frere!=NULL)
        {
            dimension_max --;
            liste_frere = liste_frere->frere_t;
        }
    }
    if (dimension_max < 0) {
        erreur("mauvaise dimension",actuel->fils_t->label);
    }
    return dimension_max;
}

void verif_dimension_expression(int dimension_max, arbre *actuel)
{
    struct _arbre *liste_frere = NULL;

    int dimension_actuel;
    
    if (actuel->type_arbre_t == MON_TABLEAU) 
    {
        int dimension_symbole = rechercher_symbole(actuel->fils_t->label);
        dimension_actuel = get_dimension_variable(dimension_symbole,actuel);
        if (dimension_actuel != dimension_max) {
            erreur("mauvaise dimension",actuel->fils_t->label);
        }
    } 
    else if (actuel->type_arbre_t == MON_VARIABLE) 
    {
        int dimension_symbole = rechercher_symbole(actuel->label);
        dimension_actuel = get_dimension_variable(dimension_symbole,actuel);
        if (dimension_actuel != dimension_max) {
            erreur("mauvaise dimension",actuel->label);
        }
        if(actuel->fils_t != NULL)
        {
            verif_dimension_expression(dimension_max,actuel->fils_t);
            liste_frere = actuel->fils_t->frere_t;
        }
    }
    else 
    {
        dimension_actuel = 0;
        if (dimension_actuel != dimension_max) {
            erreur("mauvaise dimension", actuel->label);
        }
        if(actuel->fils_t != NULL)
        {
            verif_dimension_expression(dimension_max,actuel->fils_t);
            liste_frere = actuel->fils_t->frere_t;
        }
    }

    while(liste_frere != NULL) 
    {
        verif_dimension_expression(dimension_max,liste_frere);
        liste_frere = liste_frere->frere_t;
    }
}

int verif_fonction(char* label) {
    
    int ACC_copie = ACC;
    while(ACC_copie >= 0) {
        struct _symbole *courant = TABLE[ACC_copie];
        while(courant != NULL) {
            if (!strcmp(courant->var_t,label)) {
                return courant->nb_param;
            }
            courant=courant->suivant_t;
        }
        ACC_copie--;
    }
    return -1; // la fonction n'existe pas, ou pas encore
}

int verif_param_expression(arbre *expression)
{
    int res = 0;
    struct _arbre *liste_frere = NULL;
    if (expression == NULL) {
        return res;
    }
    res++;
    
    liste_frere = expression->frere_t;

    while(liste_frere!=NULL){
        res++;
        liste_frere=liste_frere->frere_t;
    }
    return res;
}

void verif_switch(arbre *arbre_switch) {
    struct _arbre *liste_frere = NULL;
    liste_frere = arbre_switch;
    while(liste_frere->frere_t!=NULL){
        if(liste_frere->type_arbre_t == MON_CASE) {
            liste_frere=liste_frere->frere_t;
        } else {
            erreur("doit être une expression CASE.", NULL);
        }
    }
    if(liste_frere->type_arbre_t!=MON_DEFAUT)
    {
        erreur("il manque le case DEFAULT.", NULL);
    }
    return;
}

void erreur(char *description, char *terme_concerne) {
    if (terme_concerne != NULL) {
        fprintf( stderr, "%s : %s, ligne : %d\n", terme_concerne, description, yylineno );
    } else {
        fprintf( stderr, "%s, ligne : %d\n", description, yylineno );
    }
    exit(1);
}

void yyerror(char *s)
{
    fprintf(stderr,"%s : %d",s,yylineno);
    exit(1);
}