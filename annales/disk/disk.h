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
    d=floor(sqrt(d)+2);
    char * textec=malloc(1000*sizeof(char));
    if (textec==NULL)
        return NULL;
    char point[1]={"."};
    strcpy(textec, texte);
    for (int j=1; j<=d+1; j++){
        strcat(textec, point);
    }
    char * chaine = malloc(1000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    int k=0;
    for (int y=0; y<d; y++){
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                char chainetmp[0];
                chainetmp[0]=textec[k];
                strcat(chaine, chainetmp);
                k++;}
            /*else if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0 && k>(int)strlen(texte)){
                strcat(chaine, ".");
                k++;
            }*/
            else 
                strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    //printf("%s", chaine);
    return chaine;
}