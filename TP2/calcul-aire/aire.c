#include <stdio.h>

int main()
{
    int lon;
    int lar;
    printf("Longueur ?");
    scanf("%i", &lon);
    printf("Largeur ?");
    scanf("%i", &lar);
    int aire =  lon*lar;
    printf("Aire = %i\n", aire);
    return 0;
}