#include <stdio.h>

int main(){
    int M=1000000;
    int N=0;
    scanf("%i", &N);
    int tab[M];
    for (int i=0; i<M; i++){
        tab[i]=0;
    }
    printf("\n");
    int numero=0;
    for (int i=0; i<N; i++){
        scanf("%i", &numero);
        if (tab[numero]!=0){
            printf("%i\n", numero);
            return 0;
            }
        tab[numero]=numero;
    }
    printf("-1\n");
    return 0;
}