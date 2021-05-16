# Compilateur : mongcc 

## Comment installer le compilateur
Pour installer les dépendances du Compilateur :
* make install                                  Installera graphviz flex et bison.

## Comment lancer ce Compilateur
Pour lancer le compilateur : 
* Sur un fichier : make run FILE=fichier.c		Compile fichier.c et ajoute fichier.c.dot dans generation/dot et fichier.c.pdf dans generation/pdf.
* Sur tout les fichiers de test : make run_all  Compile tout les .c du dossier Test et ajoute leur .dot et .pdf dans les dossiers prévues.


### Erreur connue
Le résultat du compilateur ne sera pas celui attendue dans ces cas :
* Un appel récursif valide est fait, à la suite d'un appel de fonction qui aurai dû provoquer une erreur.   Aucune erreur ne sera déclenché.
