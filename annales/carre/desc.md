## Carré ++

Etant donné un nombre `N`, on aimerait savoir si c'est le carré d'un autre nombre plus un ie., si `N = k*k+1` pour un entier `k`.

Ecrire un programme qui lit un entier dans le terminal et affiche `PARFAIT` si l'entier est un carré plus un.
Si ce n'est pas le cas votre programme doit afficher le plus petit nombre supérieur à `N` qui est un carré plus un.

La fonction `sqrt` de la librairie math pourrait vous être utile (si vous l'utilisez, il faut ajouter l'option `-lm` lors de la compilation)

Valeurs possibles : `0 <= N <= 1000000000000000000`

### Exemples

#### Exemple 1

Entrée :
```
26
```

Sortie :
```
PARFAIT
```

26 = 5*5 + 1

#### Exemple 2

Entrée :
```
25
```

Sortie :
```
26
```