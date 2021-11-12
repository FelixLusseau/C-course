# Chemin retour Dynamique

## Rappel du problème précédent (problème 35):

L'un des produits nécessaires pour la fabrication de l'onguent magique, un minerai très rare, ne se trouve qu'en un seul endroit sur la planète, au fond de la plus vieille mine existante, jadis exploitée par le peuple nain. Désormais seuls quelques uns d'entre eux sont encore sur place, afin de guider les voyageurs (commerçants et touristes) au sein de ce dédale de cavernes et galeries.
Après avoir engagé un guide, il vous mène jusqu'à l'endroit prévu mais un petit désaccord sur le paiement de ses services le pousse à vous laisser sur place, sans aucune chance de retrouver la sortie. Heureusement votre robot à conservé en mémoire la suite des déplacements qui vous ont amené de l'entrée jusqu'à votre position actuelle, il ne vous reste plus qu'à suivre le chemin inverse !

## Nouveauté :

Cette fois-ci vous ne connaissez pas à l'avance le nombre de déplacement effectués

## Ce que doit faire votre programme :

Il existe 5 types de déplacements, représentés par 5 entiers différents :
aller à gauche (1), aller à droite (2), aller tout droit (3), monter (4) et descendre (5).

De plus l'entier 0 signifie que l'on est arrivé à destination.

Votre programme (toujours dans un fichier `chemin.c`) doit lire dans le terminal des entiers (un par ligne) correspondant au
chemin emprunté jusqu'à la destination.

Vous devez afficher la suite des déplacements à faire pour aller de votre position actuelle
à la sortie.

**Il est fortement conseillé d'utiliser une pile:
Par exemple celle-ci:  [Doc](https://bramas.gitlab.io/libtps.h/tps_stack.h.html)**.

Vous devez écrire un `Makefile` contenant un règle pour compiler le programme `chemin` (qui utilise la librairie tps) et une règle `clean`


### Exemple

entrée :
```
1
3
2
4
4
5
0
```
sortie :
```
4
5
5
1
3
2
```
