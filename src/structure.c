#include "structure.h"

int ACC = 0;

void nouvelle_adresse()
{
    // TODO realloc TABLE quand ACC == TAILLE -1
    while (TABLE[ACC] != NULL) 
    {
        ACC++;
    }
}

void detruire_table()
{
    if (ACC > 0) {
        TABLE[ACC]=NULL;
        ACC--;
    }
}

void detruire_table_fonction() {
    detruire_table();
    detruire_table();
}

arbre *creer_arbre(char *label, arbre *fils, arbre *frere, enum type_arbre mon_mon)
{
    struct _arbre *nouvel_arbre = (arbre*) malloc(sizeof(arbre));
    nouvel_arbre->type_arbre_t = mon_mon;
    nouvel_arbre->label=label;
    nouvel_arbre->frere_t=frere;
    nouvel_arbre->fils_t=fils;
    return nouvel_arbre;
}

void *ajouter_fils(arbre *actuel, arbre *fils) {
    actuel->fils_t = fils;
}

void *ajouter_frere(arbre *actuel, arbre *frere) {
    struct _arbre *frere_courant = actuel;//->frere_t;

    while(frere_courant->frere_t != NULL) {
        frere_courant = frere_courant->frere_t;
    }

    frere_courant->frere_t = frere;
}
symbole *creer_symbole(char* var_t, char* type_t) {
    struct _symbole *nouveau_symbole = (symbole*) malloc(sizeof(symbole));
    nouveau_symbole->var_t=var_t;
    nouveau_symbole->type_t=type_t;
    nouveau_symbole->dimension=0; //tab
    return nouveau_symbole;
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
        courant=courant->suivant_t;
    }
    courant->suivant_t = futur; 

    return actuel;
}

symbole *fixer_type(symbole *actuel, char* type_t)
{
    struct _symbole *courant = actuel;

    while(courant->suivant_t != NULL)
    {
        courant->type_t=type_t;
        courant=courant->suivant_t;
    }

    courant->type_t = type_t;
    return actuel;
}
// le int est le nbr de dimensions du symbol 
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
    
    char *buf = malloc(256);
    snprintf(buf,256, "%s n'est pas défini.", label);

    char *copy=malloc(256);
    strcpy(copy,buf);
    yyerror(copy);
    free(buf);
    exit(1);
}

//on verifie le type des affectation pour que le nombre de dimensions soit compatible
// exemple : int a[] et int b[][]
// verif_type_affectation accepte a=b[]
void verif_type_affectation(arbre *variable, arbre *expression) {
    int dimension_symbole;

    // On récupère la dimension du symbole de la variable et on vérifie le type de la variable.
    if (!strcmp(variable->label,"TAB") && variable->fils_t != NULL) {
        dimension_symbole = rechercher_symbole(variable->fils_t->label);
    }
    else {
        dimension_symbole = rechercher_symbole(variable->label);
    }
    int dimension_variable = get_dimension_variable(dimension_symbole, variable);
    verif_dimension_expression(dimension_variable, expression);
}


// get_dimension_variable indique le nombre de dimensions atteint en fesant a[][]
// int a[][];
// a[1]= ...;
// en verif le nombre de dimensions restante après avoir fait a[1], ici encore 1
// a[1][1] = ... ici 0 on regarde, un int
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
        char *buf = malloc(256);
        snprintf(buf,256, "%s mauvaise dimension", actuel->fils_t->label);
        char *copy=malloc(256);
        strcpy(copy,buf);
        yyerror(copy);
        free(buf);
        exit(1);
    }
    return dimension_max;
}


// verifie que l'arbre 'actuel' a bien le meme nombre de dimensions que dimensions max
// exemple :
// int a[1]
// a[1]= 1+1; il faut que l'expression 1+1 ai le meme nbr de dimension, a savoir 0 pour int
// a=1+1; ici faut car dimensions de A = 1 et 1+1 = 0
void verif_dimension_expression(int dimension_max, arbre *actuel)
{
    struct _arbre *liste_frere = NULL;

    int dimension_actuel;
    
    if (actuel->type_arbre_t == MON_TABLEAU) 
    {
        int dimension_symbole = rechercher_symbole(actuel->fils_t->label);
        dimension_actuel = get_dimension_variable(dimension_symbole,actuel);
        if (dimension_actuel != dimension_max) {
            char *buf = malloc(256);
            snprintf(buf,256, "%s : Mauvaise dimension", actuel->fils_t->label);
            char *copy=malloc(256);
            strcpy(copy,buf);
            yyerror(copy);
            free(buf);
            exit(1);
        }
    } 
    else if (actuel->type_arbre_t == MON_VARIABLE) 
    {
        int dimension_symbole = rechercher_symbole(actuel->label);
        dimension_actuel = get_dimension_variable(dimension_symbole,actuel);
        if (dimension_actuel != dimension_max) {
            char *buf = malloc(256);
            snprintf(buf,256, "%s : Mauvaise dimension", actuel->label);
            char *copy=malloc(256);
            strcpy(copy,buf);
            yyerror(copy);
            free(buf);
            exit(1);
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
             char *buf = malloc(256);
            snprintf(buf,256, "%s : Mauvaise dimension", actuel->label);
            char *copy=malloc(256);
            strcpy(copy,buf);
            yyerror(copy);
            free(buf);
            exit(1);
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

void yyerror(char *s)
{
	fprintf( stderr, "%s\n", s );
}