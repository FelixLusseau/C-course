# Pont

La seconde partie du problème permet de gérer plus de cas. Elle peut être réalisée uniquement lorsque la première partie est terminée.

## Partie 1

On cherche a construire un pont entre deux points qui sont à distance `D` (en mètres) et à une hauteur `H`. Un pont en maçonnerie standard nécessite des piliers au moins tous les 72 mètres.

Un pilier coûte 9047€ par mètre de hauteur et le tablier (la partie "plate" du pont qui relie les deux points qu'on veut connecter) coûte 21534€ par mètre.

Votre programme `pont.c` doit prendre en argument de ligne de commande un entier `D` et un entier `H` et doit afficher le coût minimum de production du pont (les piliers plus le tablier).

En cas de problème, votre programme doit retourner 42 (quitter avec le code 42).

### Exemples

#### Exemple 1

```
$ ./pont 10 2
215340
```

Un pont de 10 mètres de long n'a pas besoin de pilier donc le coût correspond uniquement à 10 fois le prix d'un mètre (21534) soit 215340


#### Exemple 2

```
$ ./pont 100 2
2171494
```

Un pont de 100 mètres de long a besoin d'un pilier (de deux mètre de hauteur) donc le coût correspond est de  `100*21534 + 2*9047 = 2171494`

#### Exemple 3

```
$ ./pont 100
$ echo $?
42
```

#### Exemple 4

```
$ ./pont -10 2
$ echo $?
42
```


## Partie 2

Dans cette partie, les deux points à relier ne se situent pas forcément à la même hauteur. La longueur `D` correspond à la distance "au sol", comme si les points étaient à la même hauteur.
La limite de 72 mètres concerne aussi une distance "au sol" sans tenir compte de l'élevation.

votre programme prends donc 3 argument de ligne de commande `D`, `H1`, et `H2`, où `H1` est la hauteur.
Votre programme doit afficher un coût arrondi à l'euro près. (vous pouvez utiliser la fonction `round`).


#### Exemple 5

```
$ ./pont 10 0 2 
219605
```
Les points sont éloignés de 10 mètres (au niveau du sol) mais l'un est au niveau du sol et l'autre à 2 mètres de hauteur. En utilisant la formule de Pythagore, on trouve que la distance réelle entre les deux points est de 10.198 mètres environ, soit un coût d'environ 219605€.

#### Exemple 6

```
$ ./pont 100 0 3 
2161968
```
Le coût minimum est obtenu en plaçant un pilier après 28 mètres du côté du points le moins haut. Ce pilier à une hauteur d telle que d/28 = 3/100, soit d = 0.84, pour un coût de 7599.48, plus le coût du tablier, soit un total de 2161968€

