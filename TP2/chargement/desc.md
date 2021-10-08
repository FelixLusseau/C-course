# Chargement

Une barre de chargement est une chaine de caractère composée du caractère `[` suivi de plusieurs fois le caractère `=` suivis de plusieurs espace ` `, et terminée par le caractère `]`. Il doit toujour y avoir 10 caractères entre `[` et `]` (que se soient des espaces ou des signes `=`).

Exemples de barre de chargement :

```
[=======   ]
[===       ]
[==========]
[          ]
```

1. Ecrire une fonction `progressBar` prenant un entier `n` en paramètre et affichant dans le terminal une barre de chargement contenant `n` signes `=`.

2. Votre fonction progressBar a-t-elle des préconditions?

3. Ecrire un programme qui demande un nombre à l'utilisateur et appelle votre fonction `progressBar` avec ce nombre. Si l'utilisateur entre un nombre plus petit que 0 affichez une barre de progression de 0, et s'il rentre un nombre plus grand que 10, affichez une barre de progression de 10.
