#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * disk(int d){
    char * chaine = malloc(10000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    chaine[0] = '\0';
    for (int y=0; y<d; y++){
        int flag=0;
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                strcat(chaine, "#");
                flag=1;}
            else if (flag!=1)
                strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    return chaine;
}

char * disk_text(char * texte){
    int d=0;
    long unsigned int diese = 0;
    int nbcarac = 0;
    while (diese<=strlen(texte)){
        nbcarac=(int)diese;
        diese = 0;
        for (int y=0; y<d; y++){
            for (int x=0; x<d; x++){
                if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                    diese++;
                }
            }
        }
        d++;
    }
    d-=1;
    char point[3]={'.'};
    char * textecopie = malloc(10000*sizeof(char));
    if (textecopie==NULL)
        return NULL;
    textecopie[0]='\0';
    strcat(textecopie, texte);
    for (int j=1; j<=nbcarac; j++){
        strcat(textecopie, point);
    }
    char * chaine = malloc(10000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    chaine[0] = '\0';
    int k=0;
    for (int y=0; y<d; y++){
        int flag=0;
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                char chainetmp[3]={' '};
                chainetmp[0]=textecopie[k];
                strcat(chaine, chainetmp);
                k++;
                flag=1;
                }
            else if (flag!=1)
                strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    //printf("%s", chaine);
    free(textecopie);
    return chaine;
}