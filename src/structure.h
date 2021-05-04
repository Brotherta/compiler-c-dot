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

enum type_arbre{
	MON_FONCTION, 
	MON_ITERATION, 
	MON_IF, 
	MON_SWITCH, 
	MON_CASE, 
	MON_DEFAUT, 
	MON_BREAK,
	MON_BLOC, 
	MON_RETURN, 
	MON_APPEL, 
	MON_TABLEAU, 
	MON_VARIABLE,
	MON_AUTRE
};


typedef struct _arbre {
	char *label;
	enum type_arbre type_arbre_t;
	struct _symbole *symbol_t;
	struct _arbre *frere_t;
	struct _arbre *fils_t;
	int id;
} arbre;

typedef struct _param {
	char *type_t;
	struct _param *suivant_t;
} param;

typedef struct _symbole {
	char *var_t;
	char *type_t;
	int dimension;
	int nb_param;
	struct _param *param_t;
	struct _symbole *suivant_t;
} symbole;

struct symbole *TABLE[TAILLE];

int ACC;
char *label_appel_recursif;
int est_recursif;
int nb_param_appel_recursif;

struct arbre *PROGRAMME;
struct recursion *la_recursion;

void yyerror(char *s);

void reset_la_recursion();
void set_la_recursion(char* label, int est_recursif, int nb_param_appel);

void nouvelle_adresse();
void detruire_table();
void detruire_table_fonction();

arbre *creer_arbre(char *label, arbre *fils, arbre *frere, enum type_arbre mon_mon);

//void affichage_arbre(arbre *arbre);

void *ajouter_fils(arbre *actuel, arbre *fils);
void *ajouter_frere(arbre *actuel, arbre *frere);

symbole *creer_symbole(char* var_t, char* type_t);
symbole *creer_symbole_fonction(char* var_t, char* type_t, symbole *liste_param);

symbole *ajouter_symbole(symbole *actuel, symbole *suivant);
void incr_dimension(symbole *actuel);

symbole *fixer_type(symbole *actuel, char* type_t);
symbole *copie_symbole(symbole *a_copier);
int rechercher_symbole(char *label);
int get_dimension_variable(int dimension_max, arbre *actuel);
void verif_type_affectation(arbre *variable, arbre *expression);
void verif_dimension_expression(int dimension_max, arbre *actuel);
int verif_fonction(char* label);
int verif_param_expression(arbre *expression);
void verif_switch(arbre *arbre_switch);
//void generer_dot($$);

#endif