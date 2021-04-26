#include "structure.h"

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

symbole *fixer_type(symbole *actuel, char* type)
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