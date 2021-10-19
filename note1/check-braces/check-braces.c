#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[1000];
    int nbo = 0;
    int posf = 0;
    fgets(str, 1000, stdin);
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]=='{')
            nbo++;
        else if (str[i]=='}'){
            if (nbo>0)
                nbo--;
            else{
                posf=i;
                printf("%s", str);
                for (int k=0; k<posf; k++)
                    printf(" ");
                printf("^ cette accolade fermante est en trop.\n");
            }
        }
    }
    if (nbo>0)
        printf("Il manque au moins un accolade ouvrante.\n");
    return 0;
}