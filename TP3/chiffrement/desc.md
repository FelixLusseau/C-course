# Chiffrement

A Télécom Physique Strasbourg, les enseignants
utilisent un code pour chiffrer les sujets des
examens. Ils pensent que c'est le meilleurs
algorithme de chiffrement qu'on peut avoir. Ils
n'en changent donc *jamais*.

Un algorithme de chiffrement consiste à transformer une
lettre par une autre de manière bijective. c'est-à-dire
qu'une lettre est toujour replacée par la même lettre,
et deux lettres différentes sont chiffrés par des lettres
différentes. Il est possible qu'une lettre soit
chiffrée par elle-même. Par exemple, l'algorithme de chiffrement
des enseignants de TPS transforme effectue les transformations suivantes:
'z'->'q', 'o'->'e', 'u'->'j' et 'n'->'s'. Ainsi la phrase 'un zoo' est chiffrée
en 'js qee'.
Pour simplifier, les lettres accentuées sont interdite et la
ponctuation, ainsi que les espaces, ne sont pas chiffrées.
Uniquement les 26 lettres minuscules sont chiffrées.

## Ce que doit faire votre algorithme
lire une chaine de charactères correspondant à
une phrase chiffrée. Puis il doit déchiffrer
la chaine et afficher le résultats.

### Exemples
#### Exemples 1
entrée :
```
fcrrc ymle cdr kxveddknmc y icfbkwwpcp
```
sortie :
```
cette algo est impossible a dechiffrer
```
#### Exemples 2
entrée :
```
km a y wyfrepkcm gkslr dkh veddknkmkrccd
```
sortie :
```
il y a factoriel vingt six possibilitees
```
#### Exemples 3
entrée :
```
uc dcpykd rek u'kpykd gekp djp tkokvciky
```
sortie :
```
je serais toi j'irais voir sur wikipedia
```