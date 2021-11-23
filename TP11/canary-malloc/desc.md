## Canary Malloc

Comme vous êtes régulièrement étourdis et qu'il vous arrive fréquemment depasser les bornes d'un tableau sans vous en rendre compte, vous décidez de créer un outils permettant de détecter de telles erreurs automatiquement (car évidement vous avez la flemme d'utiliser valgrind).


Pour cela vous allez créer votre propre fonction d'allocation de mémoire appelé `ca_malloc` qui viendra remplacer `malloc`, ainsi qu'une fonction `a_free` qui remplacera `free`.



Supposons qu'un utilisateur veux allouer un tableau de 4 `char` avec l'appel suivant `ca_malloc(4)`.
Notre fonction va alloué 4+16 octets avec malloc:
[....................]
Dans cette zone, les 4 octets du milieu représentent la zone demandée par l'utilisateur, les 8 premiers octets vont stocker un canary et les 8 derniers octets aussi.

[cccccccc....cccccccc]

L'adresse des 4 octets du milieu est retournée à l'utilisateur.

L'utilisateur ne sait pas que des canary se situent autour de la zone allouée.

`ca_malloc` fait la même chose que `malloc` mais alloue un peu plus de mémoire. Lorsqu'elle est appelée avec un argument `n` elle doit allouer les `n` octets demandés plus 8 octets avant les `n` octets et 8 octets après les `n` octets, afin d'y placer un canary (une valeur arbitraire). `ca_malloc` utilise `malloc` afin d'allouer ces ̀`n+16` octets.
Contrairement à `malloc`, `ca_malloc` ne retourne pas l'adresse situé au début de la zone allouée mais l'adresse située après le premier canary.

Lorsque `ca_free` est appelée, on vérifie que les canary n'ont pas été modifiés. S'ils ont été modifiés, c'est que l'utilisateur a modifié une zone qui ne lui appartenait pas (en dépassant les bornes de son tableau par exemple). Dans ce cas on peut afficher une erreur dans la sortie erreur (stderr en utilisant par exemple `fprintf(stderr, "Message");`). Dans tous les cas `ca_free` appelle free avec la zone totale (les `n+16` octets).

### Organisation des fichiers

vous devez implémenter vos deux fonctions dans `ca_malloc.c` et les déclarer dans `ca_malloc.h`.
Vous devez créer un Makefile avec une règle `tests` qui compile le fichier `tests.c`, et une règle `clean` qui supprime les fichiers temporaires et les executables.
