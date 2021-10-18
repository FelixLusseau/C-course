#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * disk(int d){
    char * chaine = malloc(1000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    for (int y=0; y<d; y++){
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0)
                strcat(chaine, "#");
            else 
            strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    return chaine;
}

char * disk_text(char * texte){
    int d = strlen(texte);
    d=floor(sqrt(d)+1);
    char * chaine = malloc(1000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    for (int y=0; y<d; y++){
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0 && x+y<(int)strlen(texte))
                strcat(chaine, &(texte[x+y]));
            else if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0 && x+y>(int)strlen(texte))
                strcat(chaine, ".");
            else 
            strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    return chaine;
}