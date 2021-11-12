#include "generer-plaque.h"
#include <string.h>
#include <math.h>

int main(int argc, char ** argv)
{
    if(argc != 4) 
    {
        printf("Il faut 3 arguments !!\n");
        printf("custom-plaque PRENOM NOM PLAQUE_PERSO\n");
        return 1;
    }
    Personne p = {.prenom = argv[1], .nom = argv[2]};
    char * plaqueperso=argv[3];
    /* while (strlen(plaqueperso)!=12){
        strcat(plaqueperso, ".");
    } */
    char plaque[13];
    unsigned long long int n=0;
    int e=55;
    int i=strlen(plaqueperso)-1;
    while (strcmp(plaque, plaqueperso)!=0){
    //for (n=750000; n<=754000; n++){
        while (plaque[i]!=plaqueperso[i]){
            n=n+pow(2,e);
            generer_plaque(p, n, plaque);
            printf("%s\n", plaque);
            printf("%llu\n", n);
        }
        i--;
        e-=5;
        n++;
        
    }
    //printf("%s\n", plaqueperso);
    printf("%llu\n", n);
}