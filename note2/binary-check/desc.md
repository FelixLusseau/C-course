## Binary-check

On souhaite créer un type d'entier permettant de socker un entier non signé de 32 bits dans un type plus grand (64 bits) de manière à pouvoir détecter des modifications/altérations non voulu de la mémoire.
Pour cela on va utiliser une manière simple de détection des erreurs.

Un entier non signé de 32 bits va être encodé en 64 bits en plaçant deux copies identiques de lui-même de manière contigüe en mémoire.
Par exemple, l'entier `0xF2E60305` (écrit ici en héxadécimal) sera encoder sur 64 bits par l'entier `0xF2E60305F2E60305`. De même, l'entier `0x11` (17 en décimale) sera encodé par `0x1100000011`

Ainsi, on pourra implémenter une fonction `ci_check` qui vérifie qu'un nombre n'a pas été altéré en vérifiant simplement que les 32 premiers bits sont bien égaux au 32 bits suivants.

L'opération de décodage consistera à ne retourner que les 32 premiers bits du nombre encodé. La fonction qui décode, pourra aussi vérifier, de manière optionnelle, que le nombre n'a pas été altéré, grâce à un argument passé par pointeur. Si le nombre a été altéré, le minimum des deux valeurs possibles sera retourné.

Le but de cet exercice est d'implémenter les trois fonctions suivantes:

* `uint64_t ci_encode(uint32_t value)` : encode un entier non signé 32 bits en un entier non signé sur 64 bits comme décrit précédemment.
* `int     ci_check(uint64_t value)` : vérifie si un entier non signé sur 64 bits est correct (n'a pas été altéré).
* `uint32_t ci_decode(uint64_t value, int *ok)`: decode un entier non signé 64 bits en un entier non signé sur 32 bits. Si le nombre n'est pas correct, il faut retourner le minimum parmi les deux nombres stockés. si `ok` est différent de `NULL`, alors `ok` doit pointer vers un `int` qui recevra la valeur 0 ou 1, si le nombre a été altéré ou non. (`ok` peut valoir `NULL`, et dans ce cas rien ne se passe).

Voir le programme `tests.c` en cas de doute sur ce que font les fonctions. Les type `uint32_t` et `uint64_t` sont définis dans l'entête `stdint.h`.

Les fonctions doivent être déclarées dans un fichier `checked-int.h` (le .h n'est pas fourni, à vous de l'écrire entièrement) et implémentées dans un fichier `checked-int.c`. Vous devez écrire un Makefile pour compiler le programme `tests` (avec aussi une règle `clean`).

