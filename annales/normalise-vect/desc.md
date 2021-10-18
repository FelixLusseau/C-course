## Normalisation de vecteur

Un vecteur est représenté par une structure qui est déjà définie dans le fichier `tests.c` comme cela:
```C
typedef struct vector_2D {
  double x;
  double y;
} vector_2D;

```

Vous devez écrire dans un fichier `normalise-vect.h` deux fonctions permetant de normaliser un vecteur. 
* La première nommée `norm_vect` permet de normaliser le vecteur contenu dans une variable de type `vector_2D` 
(elle accepte donc un argument de type `vector_2D *`) et ne retourne rien.
* La deuxième nommée `norm_vect_xy` permet de normaliser le vecteur dont les coordonnées sont données en arguments
(elle accepte donc deux arguments de type `double *`) et ne retourne rien.


Le fichier `tests.c` contient les tests. 

Pour normaliser un vecteur (x,y), il suffit de diviser x, respectivement y, par la norme du vecteur calculée ainsi `sqrt(x*x + y*y)`. Si la norme d'un vecteur est nulle, alors le vecteur ne doit pas être modifié. 

Si vous faites vos propre tests, il faut ajouter la librairie `math.h` pour utiliser la fonction `sqrt` et il faut ajouter l'option `-lm` à `gcc` lors de la compilation.

