## Plaque d'immatriculation

Dans une galaxy très lointaines, il existe un pays où les plaques d'immatriculation des
voitures sont générées automatiquement à partir du prénom, et du nom du propriétaire de la voiture,
et d'un numéro choisi par le propriétaire (au cas ou une personne possède plusieurs voitures).

`char * plaque(Personne p, unsigned int n)`

Cette fonction est donnée par le ministère des transports du pays. Elle
est implémentée dans le fichier `generer-plaque.c` et utilisée par le programme
`generer-plaque` (dont le main ce situe dans `generer-plaque-main.c`)
Vous pouvez le tester en compilant le programme `make generer-plaque` (après avoir renommé `Makefile.sujet` en `Makefile`) et en l'exécutant avec 3 arguments
```
$ ./generer-plaque Stephenshowla Khanfur 0
tvhtmkuaqyhx
```

Une plaque d'immatriculation est toujours une chaine d'au plus 12 caractères (plus un pour le caractère nul de terminaison).
Cette fonction est assez complexe mais en théorie il est toujours possible que deux personnes différentes
aient la même plaque d'immatriculation,
mais cela ne semble pas déranger les habitants de ce pays.

En observant la manière dont le système fonctionne, vous décidez de construire un programme
qui permet à quiconque d'avoir la plaque d'immatriculation qu'il souhaite. Votre
programme permet, pour une personne donnée et pour le texte souhaité, de choisir le numéro `n` qui
permet de générer une plaque contenant le texte souhaité. Grâce à votre programme, tout ceux qui veulent
une plaque "custom" vous paie cher et vous devenez riche.

Votre programme `custom-plaque` doit prendre 3 arguments de ligne de commande, le prénom, le nom,
et le texte souhaité sur la plaque d'immatriculation. Il doit afficher le numéro permettant
au propriétaire d'obtenir la plaque voulue (en cas de problème il retournera un code d'erreur)

Votre programme doit être efficace et doit répondre en moins de 2 secondes. Attention, choisir des plaques
de 4 caractères ou plus peut prendre beaucoup de temps avec certaines méthodes, exécutez toujours votre programme avec
la commande `timeout 2s` pour éviter de prendre trop de temps (voir exemples).

Une solution qui ne fonctionne que pour des plaques de 3 lettres ou moins donne 90% des points.
Une solution générale qui fonctionne pour toutes les longueurs raportera beaucoup plus d'argent (et la note maximale).

**Vous devez implémenter le programme `custom-plaque` ainsi que modifier le `Makefile` donné
(supprimez l'extension .sujet du fichier `Makefile.sujet` donné). Le Makefile doit contenir
une règle pour compiler votre programme et une règle `clean` qui nettoie les fichiers temporaires et l'exécutable.**


### Exemples simples

```sh
$ timeout 2s ./custom-plaque Stephenshowla Khanfur gg
24941
```

```sh
$ timeout 2s ./custom-plaque Drusroberts Evilmorgan evi
764992
```


### Exemple difficile

```sh
$ timeout 2s ./custom-plaque Onotin Barnegmagogia iamthebest
18845340854343027
```
