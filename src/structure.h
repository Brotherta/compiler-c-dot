/*
Auteur : Mascaro Valentin , Vidal Mazuy Antoine
Version : 0.4
Date derniere modif : 27/04/2021
*/

#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TAILLE 103

typedef struct _arbre {
	char *label;
	struct _symbole *symbol_t;
	struct _arbre *frere_t;
	struct _arbre *fils_t;
} arbre;


typedef struct _symbole {
	char *var_t;
	char *type_t;
	struct _symbole *suivant_t;
} symbole;


struct symbole *TABLE[TAILLE];
int ACC;

void nouvelle_adresse();
void detruire_table();

arbre *creer_arbre(char *label, arbre *fils, arbre *frere);

void affichage_arbre(arbre *arbre);

void *ajouter_fils(arbre *actuel, arbre *fils);
void *ajouter_frere(arbre *actuel, arbre *frere);

symbole *ajouter_symbole(symbole *actuel, symbole *suivant);
symbole *fixer_type(symbole *actuel, char *type);
symbole *copie_symbole(symbole *a_copier);
void rechercher_symbole(char *label);


#endif