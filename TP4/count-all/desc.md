# Count A

Ecrire un programme dans un fichier C `count-all` reçoit un argument de ligne de commande et qui affiche
le nombre d'occurrences de chacune des 26 lettres de l'alphabet. Votre programme ne fera pas la différence entre les lettes majuscules et minuscules. Les autres caractères (ponctuation, accents, etc.) seront ignorés.

En cas de problème, votre programme doit s'arrêter avec le code d'erreur 42.


## Exemples
### Exemple 1
entrée :
```
$ ./count-all abcdef
```
sortie :
```
a:1
b:1
c:1
d:1
e:1
f:1
g:0
h:0
i:0
j:0
k:0
l:0
m:0
n:0
o:0
p:0
q:0
r:0
s:0
t:0
u:0
v:0
w:0
x:0
y:0
z:0
```
### Exemple 2
entrée :
```
$ ./count-all "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
```
sortie :
```
a:29
b:3
c:16
d:19
e:38
f:3
g:3
h:1
i:42
j:0
k:0
l:22
m:17
n:24
o:29
p:11
q:5
r:22
s:18
t:32
u:29
v:3
w:0
x:3
y:0
z:0
```
