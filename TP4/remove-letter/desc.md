## Suppression de lettre

Ecrire *dans le fichier d'entête `remove-letter.h`* une fonction `removeLetter` qui prend une chaine de
caractères en premier argument et un caractère en second argument et supprime toutes les occurences de
cette lettre dans la chaine de caractères. Votre fonction doit modifier directement la chaine qui est donnée et ne pas
créer une nouvelle chaine.


Le fichier `tests.c` permet de créer un programme qui test automatiquement votre programme. Vous pouvez regarder le fichier `tests.c`. Vous pouvez aussi créer votre propre programme dans un autre fichier afin de tester votre fonction. Pour cela, vous pouvez inclure le fichier `remove-letter.h`. Exemple de programme de test :

```C
#include "remove-letter.h"

int main(void)
{
  // appel vers la fonction removeLetter(...).
}

```

### Exemples

La chaine de caractère "Hello" dont le 'e' est supprimé devient "Hllo".
La chaine de caractère "Hello" dont le 'l' est supprimé devient "Heo".
