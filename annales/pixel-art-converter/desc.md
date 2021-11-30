
# Pixel Art Converter


Le projet existant permet de compiler un programme qui peut ouvrir un fichier bpm, appliquer un filter simple et sauvegarder le résultat dans un nouveau fichier.

Compilez le programme avec la commande make et exécuter le programme afin de voir son fonctionnement. Vous pouvez faire des tests avec les images examples fournies.

Le TP est découpé en plusieurs parties qu'il préférable de faire dans l'ordre.

## Amélioration du code.

Si vous regardez la fonction main dans le fichier `pixel-art-converter.c`, vous verrez que la gestion des arguments de lignes de commande est directement dans le main. 
Vous devez déplacer cette partie du code dans une fonction dédiée afin d'améliorer la lisibilité du programme. Cela impliquera peut-être de modifier d'autres parties du code et/ou de créer de nouvelles structures et/ou de changer des signatures d'autres fonctions.

## Robustesse

Si on donne en entrée du programme un fichier qui n'est pas un fichier bmp, une erreur apparait mais n'est pas très claire. Elle indique que l'entête n'est pas correct, alors qu'il faudrait plutôt dire que le fichier n'est pas une image bmp. Pour cela il faut détecter dès le début que le fichier n'est pas une image bmp, grace aux 2 premiers octets qui sont obligatoirement `0x42` et `0x4D` en hexadecimal (c'est-à-dire les charactère "BM" en ASCII).

## Image au format Pixel Art

On aimerais sauvegarder les images au format texte que l'on appelera Pixel Art Text File.
Le format est le suivant :
* sur la première ligne, il doit y avoir les caractères `PATF`
* sur la ligne suivante il doit y avoir 2 nombres représentant la largeur `L` et la longueur `H`.
* sur la ligne suivante il doit y avoir un nombre `C` représentant la taille d'une *case* (voir exemple plus loin).
* ensuite il peut y avoir un nombre arbitraire de lignes de la forme `X: RRR VVV BBB` ou X est un caractère quelconque (lettre, chiffre ou caractère spécial), et `RRR`, `VVV` et `BBB` sont des nombres entre 0 et 255 représentant la composante rouge, verte et bleue. Cette partie s'appelle *la palette*.
* une ligne contenant uniquement le caractère `-`
* `H` lignes contenant chacune `L` caractères. Chaque caractère représente la couleur du pixel à la position donnée. Chaque caractère utilisé devra avoir été défini plus haut dans la palette, sauf le caractère espace qui par défaut signifie *blanc* (255 255 255).
* le reste du fichier est arbitraire et peut notamment contenir l'auteur de l'image par exemple.

la taille d'une case sert à extrapoler l'image au format PATF afin d'obtenir une image bmp de plus grande taille. 
Par exemple, une image au format PATF de taille 3x2 avec une taille de case égale à 10, correspond à une image "normale" de taille 30x20 ou chaque carré de 10x10 pixels aura la couleur décrite dans le fichier PATF.

### Exemple:

```
PATF
3 2
20
B: 0 0 255
R: 255 0 0
-
B R
B R

Auteur: Quentin Bramas.
```

Ce fichier représente une image 60x40 représentant un drapeau bleu blanc rouge. Dans la palette `B: 0 0 255` signifie que dans l'image, les caractères `B` sont remplacés par des pixels bleus. `R: 255 0 0` signifie que dans l'image, les caractères `R` sont remplacés par des pixels rouges.
L'image "normale" correspondante est l'image "fr_20.bmp" fournie. En passant la taille des cases de 20 à 2 on obtient l'image "fr_2.bmp".

D'ailleur l'image "fr_2.bmp" possède 2 représentation au format PATF. Les fichiers `fr_2_1.patf` et `fr_2_2.patf` sont les 2 représentations possibles.

Vous trouverez d'autres exemples dans le dossier `examples`.

### Sauvegarde

Pour commencer, vous devez ajouter une fonctionnalité au programme pour qu'il puisse sauvegarder l'image bmp donnée en entrée (ouvert grace aux fonctions existantes) au format PATF avec une taille de case de 1. Ainsi chaque pixel de l'image sera un caractère dans le fichier PATF.
De plus on considère la palette fixe très simple suivante:
```
@: 0 0 0
%: 2 2 2
#: 4 4 4
+: 8 8 8
=: 16 16 16
-: 32 32 32
:: 64 64 64
.: 128 128 128
```

L'image PATF que vous allez générer sera donc en "niveau de gris".

Votre programme doit donc prendre une option supplémentaire `-t` qui représente le type de sortie. Si `-t` est suivie de la chaine `patf` alors votre programme doit enregistrer l'image au fichier patf dans le fichier indiqué par l'option `-o`. Si `-t` est suivie de la chaine `bmp` (ou si l'option n'est pas donnée du tout) alors le format de sortie est bmp (donc utilise la fonction `save_bmp`).

Astuce: La fonction de sauvegarde au format PATF peut parcourir les pixel, calculer pour chaque pixel son niveau de gris et regarder quel caractère de la palette est le plus proche (il faut se rappeler que le caractère espace ` ` est aussi dans la palette par défaut).

### Chargement

Inversement, vous devez implémenter une fonction qui prend un chemin vers un fichier au format PATF, et retourne une structure image.

Ensuite, votre programme doit être capable de détecter automatiquement le type du fichier d'entrée. Si c'est un fichier bmp, la fonction open_bmp est utilisée, et si c'est un fichier PATF, vous devez utiliser votre fonction. 

Ensuite, lors de la lecture d'une image au format PATF, votre programme doit conserver la palette du fichier, de telle sorte que si on charge une image PATF et qu'on la sauvegarde dans un autre fichier sans appliquer de filtre, l'image obtenue soit identique à l'originale.


### Prise en charge des tailles de cases

Votre programme doit être capable de gérer des tailles de cases plus grande que 1. Pour le chargement des fichiers PATF, chaque "pixel" PATF doit être converti en un carré de `C*C` pixel dans la structure image.
Lors de la sauvegarde, votre programme doit faire la moyenne des `C*C` pixels de l'image afin de créer un "pixel" PATF. La valeur de `C` utilisée lors de la sauvegarde doit être donnée en argument de ligne de commande (avec une nouvelle option).

Dans le dossier `examples`, le fichier `cat_2.bmp` a été obtenu en transformant le fichier `cat.bmp` en `cat.patf` puis en transformant `cat.patf` en `cat_2.bmp` (idem pour `image_2.bmp`).

### Palette custom

Lors de la sauvegarde d'une image au format PATF, votre programme doit être capable d'utiliser une palette créée par l'utilisateur (par exemple donnée sous forme d'un fichier contenant uniquement une palette, ou d'options en ligne de commande).

