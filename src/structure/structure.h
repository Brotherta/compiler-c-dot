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

/*
	Enumération du type d'un arbre. Utilisé pour choisir la forme du label à la génération du DOT.
	Utilisé aussi pour faire quelques vérifications sémantique. Comme le switch et  
*/
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
	struct _symbole *symbole_t;
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

/*
	Met à jour les variables globales pour éffacer la précédente récursion. 
	A utiliser en fin de définition d'une fonction.
*/
void reset_la_recursion();

/*
	Met à jour les variables globales du possible appel récursif.
	On stocke le label de l'appel, ainsi que son nombre de paramètres.
*/
void set_la_recursion(char* label, int nb_param_appel);

/*
	Créer une nouvelle adresse en incrémentant la variable globale ACC.
	On parcours TABLE[ACC] tant qu'une table des symboles existe NULL.
*/
void nouvelle_adresse();

/*
	Détruit la TABLE des symboles actuelle. Enlève le poiteur de la table.
	On décrémente ACC.
*/
void detruire_table();

/*
	Détruit la TABLE des symboles actuelle,
	les paramètres de la fonction ainsi que le corps de la fonction.
*/
void detruire_table_fonction();

/*
	Initialise un nouvel arbre avec le label, un fils un frere et son type.
*/
arbre *creer_arbre(char *label, arbre *fils, arbre *frere, enum type_arbre mon_mon);

/*
	Ajoute la table des symboles à l'arbre courant.
*/
void *ajouter_symbole_arbre(arbre *courant, symbole *symbole_a_ajouter);

/*
	Ajoute un fils à l'arbre actuel.
*/
void *ajouter_fils(arbre *actuel, arbre *fils);

/*
	Ajoute un frère au bout de la liste de ses frères.
*/
void *ajouter_frere(arbre *actuel, arbre *frere);

/*
	Créer un nouveau symbole selon les paramètre car_t et type_t.
*/
symbole *creer_symbole(char* var_t, char* type_t);

/*
	Créer un symbole en ajoutant dans la définition du symbole,
	Une fonction, avec le nombre de paramètre, ainsi que les types de chaques paramètres.
*/
symbole *creer_symbole_fonction(char* var_t, char* type_t, symbole *liste_param);

/*
	Vérifie que le symbole à rajouter / créer n'est pas dèjà présent dans la 
	table des symboles actuelle.
*/
void verif_redefinition(char* label,symbole *table_actuel);

/*
	Incrémente de 1 la dimension.
	utilisé uniquement dans le yacc, 
	afin d'incrémenter la dimension d'un tableau au fur et à mesure qu'on le découvre. (ligne 103)
*/
void incr_dimension(symbole *actuel);

/*
	Ajoute un symbole. ( à la fin de la liste de symbole si il existe déjà un suivant )
*/
symbole *ajouter_symbole(symbole *actuel, symbole *suivant);

/*
	Permet de fixer un type à une suite de symbole déclarée en même temps.
	Par Eexemple :
		int a,b,c,d;
		fixer_type(a) va fixer à : a, b, c et d, le type int.	
*/
symbole *fixer_type(symbole *actuel, char* type_t);

/*
	Recherche le symbole label dans la TABLE. Si label n'est pas contenu
	dans la table actuelle, on cherche dans la TABLE précédente jusqu'à la table globale du pogramme.
	Retourne le nombre de dimensions du symbole
*/
int rechercher_symbole(char *label);

/* 
	Indique le nombre de dimension atteint en faisant a[][].
	int a[][];
	a[1]= ...;
	Vérifie le nombre de dimension restante après avoir fait a[1], ici encore 1
	a[1][1] = ... ici 0, sort de la boucle et termine, 0 = INT.
*/
int get_dimension_variable(int dimension_max, arbre *actuel);

/*
	Vérifie le type des affectations pour que le nombre de dimension soit compatible.
   	Par exemple : int a[] et int b[][]
  		verif_type_affectation accepte a=b[x] et accepte a[x]=b[y][z] mais refuse a[x]=b[y]; qu'importe x,y,z
*/
void verif_type_affectation(arbre *variable, arbre *expression);

/* 
 	Vérifie que l'arbre 'actuel' a bien le même nombre de dimension que 'dimension' max
	Par exemple :
   		int a[1]
   		a[1]= 1+1; il faut que l'expression 1+1 ai le même nombre de dimension, à savoir 0 pour int
  		a=1+1; ici faux car dimension de A = 1 et 1+1 = 0
 */
void verif_dimension_expression(int dimension_max, arbre *actuel);

/*
	Vérifie que label est une fonction et/ou si elle existe.
	Retourne le nombre de parametre de la fonction,
	si elle n'existe pas, retourne -1.
*/
int verif_fonction(char* label);

/*
	Retourne le nombre de fils de l'expression,
	ce qui correspond au nombre de paramètre.
*/
int verif_param_expression(arbre *expression);
/*
	Vérifie que le switch comprend bien AU MOINS un cas CASE,
	et que le dernier cas est un cas DEFAULT.
*/
void verif_switch(arbre *arbre_switch);
/*
	Si terme_concerne est null, affiche : " description : ligne "
	Si terme_concerne n'est pas null affiche : " terme_concerne : description : ligne "
*/
void erreur(char *description, char *terme_concerne);
/*
	Demandé par yacc, simple affichage de l'erreur suivie de la ligne
*/
void yyerror(char *s);

#endif