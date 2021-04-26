/*
Auteur : Mascaro Valentin , Vidal Mazuy Antoine
Version : 0.3
Date derniere modif : 14/04/2021
*/

#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TAILLE = 103;


/*
typedef struct _arbre{
	char* label;
	struct _symbole *symbol_t;
	struct _arbre *frere_t;
	struct _arbre *fils_t; // fils.label -> i  || +
} arbre;
*/

typedef struct _symbole {
	char* var_t;
	char* type_t;
	struct _symbole *suivant_t;
} symbole;



//_arbre *initialisation();

symbole *ajouter(symbole* actuel, symbole* suivant);
symbole *fixer_type(symbole *actuel, char* type);

#endif

/*
int i;  // n'aparrait pas dans l'arbre, i existe dans les symbol
int a;
main()		// premier noeud
{	
	
	i=5; // = apparait et a comme frere for et fils i et 5
	for(){  // for a pour frere i et fils =
		a = i + 5 // 
	}
}
*/