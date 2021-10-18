# Gestion Etudiants

Dans un fichier **student.h** déclarez la structure suivante :

```
typedef struct {
    char * name;
    int birthYear;
    int id;
} Student;
```

Dans le même fichier, définir une fonction `Student * student_create(void)`
qui demande dans le terminal, le nom, l'année de naissance et l'identifiant de l'étudiant (dans cet ordre)
et retourne un pointeur vers la structure `Student` correspondante. En cas de problème d'allocation, cette fonction doit retourner `NULL`. On pourra limiter la taille du nom à 1000.

Dans le même fichier, définir une fonction `void student_print(Student * s)`
qui affiche les informations de l'étudiant envoyé en argument sous le format suivant :
```
id:        identifiant
name:      nom de l'étudiant
birthYear: année de naissance
```
exemple:
```
id:        14
name:      Bob
birthYear: 1978
```

Dans le même fichier, définir une fonction `void student_free(Student * s)`
qui libère la mémoire qui a été allouée pour l'étudiant passé en argument.
Si le pointeur passé en argument est `NULL`, cette fonction ne fait rien.

