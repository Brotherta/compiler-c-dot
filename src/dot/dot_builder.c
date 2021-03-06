#include "dot_builder.h"
int id_acc = 0;

void creer_fichier_dot(arbre *arbre) {
    FILE *fd_dot;
    fd_dot=fopen("_tmp_file.dot","w+");

    fprintf(fd_dot, "digraph exempleminiC {\n");
    creer_node(arbre, fd_dot);
    assigner_node(arbre, fd_dot);
    fprintf(fd_dot, "\n}");

    fclose(fd_dot);
}


void creer_node(arbre *arbre, FILE *le_dot) {
    struct _arbre *liste_frere = NULL;
    char* forme = malloc(256);
    forme = "";

    switch(arbre->type_arbre_t) {
        case MON_FONCTION: 
            forme = " shape=invtrapezium color=blue";
            break;
        case MON_IF: 
            forme = " shape = diamond";
            break;
        case MON_BREAK:
            forme = " shape = box";
            break;
        case MON_RETURN: 
            forme= " shape=trapezium color = blue";
            break;
        case MON_APPEL:
            forme = " shape=septagon";
            break;
        default:
            break;
    }
    
    arbre->id = id_acc;
    fprintf(le_dot,"\tnode_%d [label =\"%s\"%s]\n", id_acc, arbre->label, forme);
    
    if(arbre->fils_t != NULL)
    {
        id_acc++;
        creer_node(arbre->fils_t, le_dot);
        liste_frere = arbre->fils_t->frere_t;
    }
    
    while(liste_frere != NULL) 
    {
        id_acc++;
        creer_node(liste_frere, le_dot);
        liste_frere = liste_frere->frere_t;
    }
}

void assigner_node(arbre *arbre, FILE *le_dot)
{
    struct _arbre *liste_frere = NULL;
    if(arbre->fils_t != NULL)
    {
        fprintf(le_dot,"\tnode_%d -> node_%d\n",arbre->id, arbre->fils_t->id);
        assigner_node(arbre->fils_t, le_dot);
        liste_frere = arbre->fils_t->frere_t;
    }
    
    while(liste_frere != NULL) 
    {
        fprintf(le_dot, "\tnode_%d -> node_%d\n",arbre->id,liste_frere->id);
        assigner_node(liste_frere, le_dot);
        liste_frere = liste_frere->frere_t;
    }

}
