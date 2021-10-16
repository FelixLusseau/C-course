## Zorro

Zorro aimerait signer numériquement ses exploits.

Ecrire un programme (dans le fichier `zorro.c`) qui lit un entier `n` dans le terminal et affiche
un grand Z de taille `n` (`n` colonnes et `n+1` lignes).
Un Z de taille `n` est constitué de `n` caractères `_` sur la première ligne,
 `n-1` caractères `_` sur la `n+1`-ème ligne, et `n` caractères `/` sur la diagonale.

**Les lignes ne doivent pas se terminer par un espace** ie., le retour à la ligne doit être placé après le dernier caractère visible de la chaque ligne.

Si `n` est plus petit ou égal à 1, votre programme devra afficher "IMPOSSIBLE".

### Exemples
#### Exemple 1

Entrée :
```
1
```
Sortie :
```
IMPOSSIBLE
```
#### Exemple 2

Entrée :
```
2
```
Sortie :
```
__
 /
/_
```
#### Exemple 2

Entrée :
```
5
```
Sortie :
```
_____
    /
   /
  /
 /
/____
```
