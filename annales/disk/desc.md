## Disque

# Partie 1

Déclarer **dans le fichier d'entête `disk.h`** une fonction `disk` qui retourne une 
chaine de caractère représentant un disque (voir les exemples pour comprendre).
En cas de problème, votre fonciton devra retourner `NULL`.

Votre fonction prendra en argument un entier positif correspondant au diamètre du disque.
Ce nombre correspond donc au nombre de lignes contenues dans votre chaine de caractères. Cela correspond aussi à la taille de chacune des lignes.

Pour dessiner un disque, le caractère à la ligne `y` et à la colonne `x` dans la chaine doit être
le caractère `'#'` si l'inégalité suivante est vraie : 
```
((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0
```
où `d` est le diamètre voulu.

**Attention, un programme qui ne compile pas ne rapporte aucun point**.

Le fichier `tests.c` est un programme qui test automatiquement votre fonction.
Vous pouvez aussi créer votre propre programme dans un autre fichier afin de tester votre fonction.
Pour cela, vous pouvez inclure le fichier `disk.h`.
Exemple de programme de test :

```C
#include "disk.h"

int main(void)
{
  // appel vers la fonction disk(...).
}
```

### Exemple 1

`disk(4)` doit retourner la chaine de caractères suivante:
```
 ##
####
####
 ##
```
Ce qui correspond en fait à ça : `" ##\n####\n####\n ##"`

**Attention, on parle bien de retour et non d'affichage!!**

**Attention, observez bien qu'il n'y a pas d'espace entre les caractères '#' et les fins de ligne!**


### Exemple 2

`disk(10)` doit retourner la chaine de caractères suivante:
```
   ####
 ########
 ########
##########
##########
##########
##########
 ########
 ########
   ####
```

# Partie 2

Pour cette partie il faut écrire une fonction `disk_text` dans le même fichier. 
Le problème est similaire à la partie 1, mais cette fois-ci, 
au lieu d'écrire uniquement des caractères `'#'`, 
vous devez écrire le texte donné en argument, que vous complèterez avec le caractère `'.'` pour
former un disque.
Par ailleur le diamètre n'est pas donné et devra être calculé de manière à minimiser le nombre 
de `'.'` finaux.

### Exemple

`disk_text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")` doit retourner 

```
    Lorem
   ipsum do
 lor sit ame
 t, consecte
tur adipiscin
g elit, sed d
o eiusmod tem
por incididun
t ut labore e
 t dolore ma
 gna aliqua.
  .........
    .....
```

