# Mélange explosif
(crédit : france-ioi.org)

Les chimistes de l'université ont mis au point un nouveau procédé de fabrication d'un onguent qui permet une cicatrisation très rapide des blessures. Ce procédé est cependant très long et nécessite une surveillance de tous les instants de la préparation en train de chauffer, et ce parfois pendant des heures. Confier cette tâche à un étudiant n'est pas possible, ils s'endorment toujours ou ne font pas attention… et cela risque alors d'exploser !
Un dispositif automatique de surveillance de la préparation serait donc intéressant. Celui-ci surveillerait la température toutes les 15 secondes, et si celle-ci devient anormale alors une alarme devrait sonner, afin de prévenir tout le monde.

## Ce que doit faire votre programme :


Votre programme (écrit dans un fichier `temperatures.c`) devra lire trois entiers : le nombre total de mesures envisagées ainsi que la température minimum et maximum autorisées. Les entiers suivants seront les différentes températures relevées au cours du temps.
Tant que les températures relevées restent dans le bon intervalle, votre programme devra écrire le texte « Rien à signaler », mais dès que la température n'est pas bonne il doit écrire le texte « Alerte !! » et s'arrêter.

### Exemples

#### Exemple 1
entrée :
```
5
10
20
15
10
20
0
15
```
sortie :
```
Rien à signaler
Rien à signaler
Rien à signaler
Alerte !!
```

#### Exemple 2
entrée :
```
3
0
100
15
50
75
```
sortie :
```
Rien à signaler
Rien à signaler
Rien à signaler
```
