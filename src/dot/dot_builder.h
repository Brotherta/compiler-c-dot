#ifndef _DOT_BUILDER_H
#define _DOT_BUILDER_H

#include "../structure/structure.h"

void creer_fichier_dot(arbre *arbre);
void creer_node(arbre *arbre, FILE *le_dot);
void assigner_node(arbre *arbre, FILE *le_dot);

#endif
