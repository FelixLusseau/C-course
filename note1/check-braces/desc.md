# Check-Braces

On souhaite vérifier si toutes les accolades d'un code en langage C sont bien formées, 
c'est-à-dire si chaque accolade ouvrante `{` est bien fermée par la suite par une 
accolade fermante `}`.

Votre programme doit donc lire l'entrée standard du terminal un ensemble arbitraire de 
ligne de code en language C (qui correspondent en fait à un seul fichier) et dire à la 
fin si les accolades sont correctes.

Les 3 premiers tests ne contiennent qu'une seule ligne, donc commencez par ne résoudre 
le problème que dans ce cas là et vous complèterez votre programme quand ces premiers 
tests fonctionneront.

Ensuite, lorsqu'il y a plusieurs lignes, on peut tester grace à la fonction `feof(stdin)` 
s'il reste ou non du contenu à lire. Tant qu'il reste du contenu à lire (et qu'il n'y a 
pas de problème avec les accolades), vous devez lire l'entrée et lorsqu'il n'y a plus 
rien à lire vous devez afficher une erreur ou rien du tout (si aucune erreur).

Si une erreur est détéctée, soit il a une accolade ouvrante en trop et vous devez afficher 
"Il manque au moins un accolade ouvrante.", soit il a une accolade fermante en trop et vous 
devez afficher la ligne entière où cette accolade se situe, et afficher un indicateur `^` 
en dessous de l'accolade concernée, suivie du texte "cette accolade fermante est en trop."

Si vous voulez tester votre programme, vous pouvez fermer l'entrée standard (et donc indiquer
à votre programme qu'il ne reste plus de contenu à lire) en faisant le raccourci clavier
suivant: `Ctrl + D` lorsque la ligne du terminal est vide. Exemple, vous lancez votre programme,
écrivez "abc", puis entrée, puis `Ctrl + D`, ainsi un programme utilisant fgets (ou getchar)
pourra vérfier qu'après la seconde ligne, la fonction `feof(stdin)` returne 1.
Ou bien, vous pouvez donner en entrée le contenu d'un fichier ainsi: 

```
./check-braces < FICHIER_ENTREE
```

### Exemples

#### Exemple 1

Entrée:
```
ab { cd } ef
```

Sortie:
```
```
(aucune sortie)

Peut être testé ainsi:
```
./check-braces < test-0/in
```

#### Exemple 2

Entrée:
```
abc } def
```

Sortie:
```
abc } def
    ^ cette accolade fermante est en trop.
```

Peut être testé ainsi:
```
./check-braces < test-1/in
```

la ligne "abc } def" doit bien être affichée en sortie (donc elle apparaît 2 fois 
dans le terminal, une fois par celui qui écrit la ligne dans le terminal, et une 
fois car votre programme affiche cette ligne aussi).

#### Exemple 3

Entrée:
```
abc { def
```

Sortie:
```
Il manque au moins un accolade ouvrante.
```

Peut être testé ainsi:
```
./check-braces < test-2/in
```


