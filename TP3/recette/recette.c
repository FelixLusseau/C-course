#include <stdio.h>

int main(){
    int poids[10]={9, 5, 12, 15, 7, 42, 13, 10, 1, 20};
    int prix = 0;
    int poidsing;
    for (int i=0; i<=9; i++)
    {
        poidsing=0;
        scanf("%i", &poidsing);
        prix+=poidsing*poids[i];
    }
    printf("%i\n", prix);
    return 0;
}