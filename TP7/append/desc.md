# Ajout

Le but de l'exercice est d'écrire une fonction qui permet de rajouter un élément à un tableau dynamiquement alloué en augmentant la taille alloué automatiquement.

Vous devez écrire une fonction `append` qui prends 3 arguments: un tableau d'entier, un entier contenant la taille du tableau et l'entier à ajouter à la fin du tableau. Attention, les deux premiers arguments sont envoyé par pointeur, car leur valeur seront modifiées par la fonction.

La fonction retourne un entier qui permet de dire si tout s'est bien passé (voir le fichier tests.c pour plus de détail).


Le fichier `append.h` contient le prototype de la fonction. Vous devez:
* implémenter la fonction `append` dans un fichier `append.c`
* écrire un `Makefile` contenant une règle `tests` qui permet de compiler le programme `tests.c` déjà fourni, et une règle clean qui permet de supprimer les fichiers temporaire de compilation et l'exécutable.
