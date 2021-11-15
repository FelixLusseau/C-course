#Carte de réduction
crédit: france-ioi.org

La description est similaire au problème carte-reduction, uniquement les limites ont changées.

Vous êtes employé dans un cinéma et votre patron décide de lancer une offre spéciale.
Toute personne possédant une carte de fidélité a le droit, pendant un mois,
de voir un film gratuit par jour. Bien entendu certaines personnes vont essayer de
tricher en venant plusieurs fois au cinéma dans la même journée et votre travail
consiste à détecter ces tricheurs.

Si vous trouvez un tricheur, vous devez laisser votre caisse à un collègue,
et emmener le tricheur chez votre patron qui lui confisquera sa carte de fidélité.

### Limites de temps

Temps : pas trop long

### Limites

0 <= M <= 1 000 000 000 000, la valeur possible pour un numéro de carte de fidélité.
0 <= N <= 10 000, le nombre de clients venant au cinéma en une seule journée.

### Entrée

La première ligne contient l'entier N, le nombre de clients de la journée.
La seconde ligne contient leurs N numéros de carte de fidélité.

### Sortie

Vous devez écrire un seul entier, le numéro de carte de fidélité du premier tricheur que vous avez trouvé.
S'il n'y avait pas de tricheur, écrivez la valeur -1.

### Exemples

#### Exemple 1
entrée :
```
4
10 2 3 2
```

sortie :
```
2
```

#### Exemple 2
entrée :
```
5
11 3 17 13 19
```
sortie :
```
-1
```
