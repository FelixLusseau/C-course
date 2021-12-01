# BMP-message

En partant de la correction de l'exercice TP12/bmp-msg disponible sur moodle, le but de ce TP compléter ce projet en réalisant les améliorations suivantes. Vous pouvez sauter des fonctionnalités si vous le souhaitez. Pensez aussi à ajouter des tests dans le fichier `test.sh` montrant le fonctionnant de votre programme. Vous pouvez aussi ajouter des tests dans le fichiers `tests/tests.c` (d'ailleurs dans le dossiers tests fait un `make cov` et observer la couverture de vos tests sur la page `tests/rapport/index.html`).

* Implémentez une fonction `void printUsage(void)` qui affiche une aide expliquant comment utiliser le programme. Cette fonction devra être appelée si l'option `-h` est donnée en argument de ligne de commande ou dès qu'une erreur est réalisée concernant les arguments de ligne de commande. Pensez à mettre à jour cette fonction durant l'ajout des fonctionnalité.
* Lors de l'encodage, insérer avant la taille du message à coder, 4 octets ayant la valeur `0b10101010` encodés de la même manière que les autres octets (c'est à dire que chaque octet est en fait encodé sur 8 octets dans l'image, en utilisant la fonction `byte_encode`). Ainsi les informations encode sont :
    `[4 octets "magiques"][8 octets pour la taille du message à codé][le message à coder]`.
  Lors du décodage, il faudra vérifier que ces octets sont présents avant de décoder le reste du message. On pourra ainsi prévenir l'utilisateur (avec une nouvelle erreur) lorsque l'image que l'on souhaite décoder ne contient pas de message à décoder.

* La fonction `getDataSize` retourne la taille en octets du tableau de pixels. Elle est obtenue en lisant l'entier à la position `0x22` (32 en décimal). Cependant, dans certaines images bmp, cette valeur est nulle (c'est le cas de `cat-2.png` et de `image.bmp`). Corrigez la fonction `getDataSize` pour que, si l'entier lu est nul, calcul la taille en octets du tableau de pixels en utilisant cette formule:
```
size = (uint32_t)(((bitsPerPixel*width+31)/32)*4*height)
```
où `bitsPerPixel` est un `uint16_t` qui peut être lu à la position `28`et `width` et `height` sont des `int32_t` lus aux position `38` et `42`.

* Ajoutez un argument de ligne de commande `-f` qui est suivit d'un nombre ayant la valeur, soit `1`, `2`, ou `4` (afficher une erreur sinon). Cet argument représente un facteur de compression du message caché dans l'image. La valeur 1 est la valeur par défaut (si jamais l'argument n'est pas donné). Ce facteur correspond au nombre de bits utilisé pour stocker le message dans chaque octet de l'image.
  Par défaut, le dernier bit est utiliser pour le message, mais si le facteur est 4, alors les 4 derniers bits de chaque octet de l'image doivent être utilisé pour stocker le message. Ainsi, uniquement 2 octets de l'image servent à stocker 1 octet du message (contre 8 par défaut).
  La ligne suivante permet de stocker 4 bits du message c dans le pixel. si bi = 0, ce sont les 4 bits les plus à droite, si bi = 1, ce sont les 4 bits de gauche.
  ```
  pixel = (pixel & 0b11110000) | ((c & (0b1111 << bi)) >> bi);
  ```
  Lorsque le facteur vaut 2, la ligne suivante permet de stocker 2 bits du message c dans le pixel. si bi = 0, ce sont les 2 bits les plus à droite, si bi = 1, ce sont les 2 bits suivant, bi = 2 les 2 bits suivants, bi = 3, le 2 bits les plus à gauche.
  ```
  pixel = (pixel & 0b11111100) | ((c & (0b11 << bi)) >> bi);
  ```

  Pour décoder un message avec un facteur égale à 4, il faut exécuter cette ligne en utilsant 2 pixels consécutifs (et bi = 0, 1).
  ```
  byte = byte | ((pixel & 0b00001111) << bi);
  ```

  Pour décoder un message avec un facteur égale à 2, il faut exécuter cette ligne en utilsant 4 pixels consécutifs (et bi = 0, 1, 2, 3).
  ```
  byte = byte | ((pixel & 0b00001111) << bi);
  ```
  Comme le facteur doit être connu pour encode/décoder le message, il faut le stocker dans l'image aussi (avec un facteur 1).

  Ainsi, l'image cat-2.bmp peut être encoder dans l'image cat.bmp avec un facteur 4 alors qu'elle est trop grande avec un facteur 1. L'image cat_in_cat_f4.bmp vous donne un aperçu du résultat (l'image est visiblement altérée). 
  (je l'ai encodé avec la commande `bin/bmp-msg -e -i tests/cat.bmp -o tests/out.bmp -f 4 <  tests/cat-2.bmp`).

* L'encodage peut être assez long (par exemple `bin/bmp-msg -e -i tests/image.bmp -o tests/out.bmp <  tests/cat-2.bmp`). Ajouter un indicateur de la progression de l'encodage, sous forme d'une barre de progression ou d'affichage d'un pourcentage, comme vous voulez.

* Améliorez les performances de l'encodage/décodage, en lisant 8 octets (ou 4, ou 2 en fonction du facteur) des fonction encode_byte et decode_byte, afin qu'il n'y ait plus qu'une seule écriture et une seul lecture dans chaque fonction

* Vous pouvez encore améliorer les performances (rendant l'encodage presque instantanné) en lisant tous les pixels avec `fread` au début de la fonction `encode`, dans un tableau, puis en envoyant ce tableau à la fonction `encode_byte` (et d'autres informations qui vous semblent pertinantes), puis en réécrivant ce tableau modifié d'un seul appelle à `fwrite`.

* Implémentez le fait que, si le fichier en entrée n'est pas une image et semble être du texte (en testant par exemple si les 5 premiers caractères sont "affichable" avec la fonction `isprint`), alors le message à encoder doit être caché dans le texte de la manière suivante. Vous devez insérer à la fin du fichier des caractères spéciaux invisibles. Pour chaque bit de chaque octet `c` du message, si c'est un 1 il faut insérer `"\u2060"`, si c'est un 0 il faut insérer `"\u200B"`. Ensuite écrire la taille du message en suivant le même principe (encoder les 8 octets de la variable `length` de cette manière). Chaque chaine de caractères `"\u2060"` et `"\u200B"` correspond en fait à un caractère unicode invisible qui est codé en 3 octets dans un texte. Ainsi, les 8 octets de la variables `length` sont codé dans les `8*8*3` dernier octets du fichier texte contenant le message caché. Un exemple de texte avec un message caché peut être trouvé dans le fichier `tests/textWithHiddenMessage.txt`.


