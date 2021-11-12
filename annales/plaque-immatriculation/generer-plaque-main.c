#include "generer-plaque.h"

int main(int argc, char ** argv)
{
    if(argc != 4) 
    {
        printf("Il faut 3 arguments\n");
        printf("generer-plaque PRENOM NOM NUMERO\n");
        return 1;
    }
    Personne p = {.prenom = argv[1], .nom = argv[2]};
    char plaque[13];
    generer_plaque(p, atoll(argv[3]), plaque);
    printf("%s\n", plaque);
}