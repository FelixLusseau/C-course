# Mölkky

Au jeu du Mölkky, le nombre de points marqués après un coup dépend du nombre de quille renversées :
* Si le lancer fait tomber une seule quille en bois alors il marque le nombre de point inscrit sur celle-ci. Exemple : si le lanceur renverse la quille numéro 6 il marquera 6 points.
* Si le lancer renverse plusieurs quilles simultanément, c’est le nombre de quilles qui ont été touchées et renversées qui comptent. Ex : imaginons qu’un joueur touche les quilles 5,6 et 12 en même temps, on ne lui comptera uniquement 3 points et non pas 5+6+12 !

Le but est d'attendeindre le score exact de 50. Lorsque le score d'une personne dépasse 50, alors il retombe à 25.

Voici un programme qui simule une partie de Mölkky d'une personne seule (le but pour cette personne étant de gagner en moins de coup possible).


```c
#include <stdio.h>


int main(void) {
  int score = 0;
  int nbLancer = 0;
  while(!isWin(score)) {

    nbLancer++;
    printf("🎳\nNombre de quilles tombées? ");
    int nbQuilles;
    scanf("%i", &nbQuilles);
    printf("Somme des points des quilles tombées? ");
    int sumQuilles;
    scanf("%i", &sumQuilles);

    int points = getScore(nbQuilles, sumQuilles);

    score = newScore(score, points);

    printf("Vous avez renversé %d quilles dont la somme des"
           " points fait %d, vous marquez donc %d points\n"
           "Votre score est maintenant de %d\n",
           nbQuilles, sumQuilles, points, score);
  }
  printf("Gagné 🏆 🎉 (en %d lancers)\n", nbLancer);
}
```

1. Ecrire la fonction `getScore` qui prends deux arguments, le nombre de quilles renversées et la somme des points des quilles renversées, et retourne le nombre de points marqués

2. Ecrire une fonction `newScore` qui prends deux arguments, le score d'une personne avant le lancer et le nombre de points marqués par un lancer, et qui retourne son nouveau score. Exemple, si le score d'une personne était 43 et qu'il marque 3 alors la fonction retourne 46. Par contre s'il marque 10 points, la fonction retourn 25

3. Ecrire une fonction `isWin` qui prend un score en argument et qui retourne 1 si le score est gagnant (c'est-à-dire 50) et 0 sinon.
