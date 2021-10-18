
#include "tps_unit_test.h"
#include "disk.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(void) 
{

  // Lire le nombre d'allocation qui vont réussir
  scanf("%i", &__remaining_alloc);

  // Lire un nombre. Si ce nombre est 1, utiliser la fonction sur du texte
  // Si ce nombre est 0, utiliser la fonction avec '#' en donnant un diamètre
  int with_text = 0;
  scanf("%i", &with_text);

  char * str;

  if(with_text)
  {
    while(getchar() != '\n'); // ignore reste de la ligne

    char input_str[1000];
    fgets(input_str, 1000, stdin);
    input_str[strlen(input_str) - 1] = '\0';
     // Générer la chaine à partir du texte
    str = disk_text(input_str);
  }
  else
  {
    // Lire le diamètre voulue
    int diametre;
    scanf("%i", &diametre);

    // Générer la chaine
    str = disk(diametre);
  }

  if(str == NULL)
  {
    return 1;
  }

  // L'afficher
  puts(str);

  // Libérer la chaine
  free(str);

  return 0;
}
