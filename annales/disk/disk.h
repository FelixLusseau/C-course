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
    int d = strlen(texte);
    d=floor(sqrt(d)+2);
    char point[2]={'.'};
    //printf("\n%c\n", point[0]);
    /* char * textec=malloc(10000*sizeof(char));
    if (textec==NULL)
        return NULL;
    textec[0] = '\0';
    strcpy(textec, texte); */
    //texte[strlen(texte) - 1] = '\0';
    for (int j=1; j<=d+1; j++){
        strcat(texte, point);
    //    printf("%s\n", texte);
    }
    char * chaine = malloc(1000*sizeof(char));
    if (chaine==NULL)
        return NULL;
    chaine[0] = '\0';
    int k=0;
    for (int y=0; y<d; y++){
        int flag=0;
        for (int x=0; x<d; x++){
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                char chainetmp[0];
                printf("textek %c\n", texte[k]);
                chainetmp[0]=texte[k];
                printf("chainetmp %s\n", chainetmp);
                strcat(chaine, chainetmp);
                k++;
                flag=1;
                printf("chaine %s\n\n", chaine);
                printf("chainetmp2 %s\n", chainetmp);}
            /*else if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0 && k>(int)strlen(texte)){
                strcat(chaine, ".");
                k++;
            }*/
            else if (flag!=1)
                strcat(chaine, " ");
        }
        strcat(chaine, "\n");
    }
    //printf("%s", chaine);
    return chaine;
}