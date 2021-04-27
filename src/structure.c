#include "structure.h"



arbre *creer_arbre(char *label, arbre *fils, arbre *frere)
{//$$ = (symbole*) malloc(sizeof(char*)*4); $$->var_t=$1;
    struct _arbre *nouvel_arbre = (arbre*) malloc(sizeof(arbre));
    nouvel_arbre->label=label;
    //arbre->symbol_t=
    nouvel_arbre->frere_t=frere;
    nouvel_arbre->fils_t=fils;
    return nouvel_arbre;
}

void affichage_arbre(arbre *arbre)
{
    struct _arbre *liste_frere = NULL;
    if(arbre->fils_t != NULL)
    {
        printf("%s -> %s        ",arbre->label, arbre->fils_t->label);
        affichage_arbre(arbre->fils_t);
        liste_frere = arbre->fils_t->frere_t;
    }
    
    while(liste_frere != NULL) 
    {
        printf("%s -> %s        ",arbre->label,liste_frere->label);
        affichage_arbre(liste_frere);
        liste_frere = liste_frere->frere_t;
    }
}

// for(int i; cond ; incr)
// $$=creer_arbre(for,$2,$3)

void *ajouter_fils(arbre *actuel, arbre *fils) {
    actuel->fils_t = fils;
}

void *ajouter_frere(arbre *actuel, arbre *frere) {
    actuel->frere_t = frere;
}


symbole *ajouter(symbole *actuel, symbole *futur) {
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

symbole *fixer_type(symbole *actuel, char *type)
{
    struct _symbole *courant = actuel;

    while(courant->suivant_t != NULL)
    {
        courant->type_t=type;
        courant=courant->suivant_t;
    }

    courant->type_t = type;
    return actuel;
}