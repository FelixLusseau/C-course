## Latex Indent

Faire un programme qui indente un fichier latex.

Un fichier latex est un fichier texte qui contient des macros (par exemple `\textit{texte}` qui signifie que `texte` sera en italic).

Un couple de macros est particulièrement important: `\begin{env}` et `\end{env}` qui permettent d'ouvrir et de fermer un environement. Ce qui se situe entre les deux macros peut être vu comme un **block** de code latex. 
Les environements peuvent s'imbriquer et permettent généralement de structurer le document latex. C'est pourquoi il est intéressant de les indenter.

Exemple le document suivant:
```latex
\begin{document}
\begin{center}
{\large titre}
\end{center}
Contenu
\end{document}
```
serait plus lisible ainsi:
```latex
\begin{document}
  \begin{center}
    {\large titre}
  \end{center}
  Contenu
\end{document}
```

**Dans cette exercice on souhaite une indentation de 2 espaces par environement.**

Votre programme doit prendre 1 ou 2 arguments de ligne de commande. Le premier argument correspond au fichier latex qu'il faut indenter. Le deuxième argument, s'il est donné, correspond au fichier où il faut enregistrer la version indenter du premier fichier latex.
S'il n'y a pas de deuxième argument, la version indentée du fichier latex est affiché directement dans le terminal.

Les fonctions suivantes pourront vous être utiles (`strstr` chercher la position d'une sous-chaine dans une autre, `isspace` dit si oui ou non un caractère est un espace ou une tabulation ou `\n` ou similaires)

**On pourra supposer que les lignes ne font jamais plus de 1000 caractères.**

Dans cet exercice on suppose que vous n'avez pas à modifier le contenu des lignes (appart évidement les espaces en début de ligne).

En cas d'erreur votre programme devrat quitter avec un code d'erreur. Le code d'erreur 1 en cas d'argument de ligne de commande manquant, le code d'erreur 2 en cas de problème avec l'ouverture du fichier d'entrée, et le code d'erreur 3 en cas de problème avec l'ouverture du fichier de sortie.

Vous devez aussi créer un makefile avec une règle `latex-indent` qui génère le programme du même nom, et une règle `clean` qui nettoie le dossier courant.

#### Détails

Au début vous pourrez supposer qu'il y a au plus une seule macro \begin et une seule macro \end par ligne (cela fonctionnera jusqu'à 75% des tests).

Si une ligne contient `n` fois la macro `\begin` le niveau d'intendation augmente de `n` (donc de `2n` espaces) **à partir de la ligne suivante**.

Si une ligne contient `n` fois la macro `\end` le niveau d'intendation diminue de `n` (donc de `2n` espaces) **dès cette ligne si la ligne commence par une macro `\end`** et **à partir de la ligne suivante si la ligne ne commence pas par une macro `\begin`** (en ignorant les espaces).


#### Exemple 1

Le texte suivant:
```latex
text
\begin{document}
\begin{center} {\large titre} \end{center}
Contenu
\end{document}
text
```
sera indenté comme cela:
```latex
text
\begin{document}
  \begin{center} {\large titre} \end{center}
  Contenu
\end{document}
text
```

#### Exemple 2
Le texte suivant:

```latex
\begin{document}
\begin{center} {\large titre} 
Autre texte 
\end{center}
Contenu
\end{document}
```
sera indenté comme cela:
```latex
\begin{document}
  \begin{center} {\large titre} 
    Autre texte 
  \end{center}
  Contenu
\end{document}
```


#### Exemple 3
Le texte suivant:

```latex
\begin{document}
\begin{center} {\large titre} 
Autre texte \end{center}
Contenu
\end{document}
```
sera indenté comme cela:
```latex
\begin{document}
  \begin{center} {\large titre} 
    Autre texte \end{center}
  Contenu
\end{document}
```
Attention, ici on voit que `Autre texte \end{center}` est indentée de deux niveaux (4 espaces). Alors que si la ligne avait été simplement `\end{center}` (ou même `    \end{center}`) elle n'aurait été indentée que de un niveau (2 espaces) comme dans l'exemple précédent.

#### Exemple 4

Le texte suivant:
```latex
\begin{document}
           \begin{center} 
   {\large titre} 
               \end{center}
    Contenu
\end{document}
```
sera indenté comme cela:
```latex
\begin{document}
  \begin{center} 
    {\large titre} 
  \end{center}
  Contenu
\end{document}
```