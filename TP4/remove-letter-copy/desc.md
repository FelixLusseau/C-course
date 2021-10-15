## Suppression de lettre avec copie

Cette exercice est le même que le problème (remove-letter) mais cette fois-ci la chaine passée en paramètre **ne doit pas
être modifiée**. Une nouvelle chaine contenant le résultat doit être retournée par la fonction.

Ecrire *dans le fichier d'entête `remove-letter.h`* une fonction `removeLetter` prend une chaine de
caractères en premier argument et un caractère ne second argument et retourne **une nouvelle chaine de caractère** qui
correspond à la chaine fournie dont toutes les occurences de
la lettre ont été supprimées.

En cas de problème votre fonction doit retourner un pointeur null (`NULL`).


Le fichier `tests.c` permet de créer un programme qui test automatiquement votre programme. Vous pouvez aussi créer votre propre programme dans un autre fichier afin de tester votre fonction. Pour cela, vous pouvez inclure le fichier `copy.h`. Exemple de programme de test :

```C
#include "remove-letter.h"

int main(void)
{
  // appel vers la fonction removeLetter(...).
}

```

### Exemples

La chaine de caractère "Hello" dont le 'e' est supprimé devien "Hllo".
La chaine de caractère "Hello" dont le 'l' est supprimé devien "Heo".
