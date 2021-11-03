#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

int main(){
    int n;
    unsigned long int res=0;
    scanf("%i", &n);
    if (n<1 || n>30){
        printf("Nombre pas dans le bon intervalle !\n");
        return 42;
    }
    int dim = n;
    unsigned int tab_init[dim][dim];
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
                tab_init[i][j]=0;
        }
    }
    for (int i=0; i<dim; i++){
        for (int j=0; j<=i; j++){
            //printf("i,j = %i %i\n", i, j);
            scanf("%i", &tab_init[i][j]);
        }
    }
    /*printf("\n");
    for (int k=0; k<dim; k++){
        for (int l=0; l<dim; l++){
                printf("%i ", tab_init[k][l]);
        }
        printf("\n");
    }*/
    
    unsigned int tab[dim][dim];
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
                tab[i][j]=0;
        }
    }
    for (int k=0; k<dim; k++){
        tab[dim-1][k]=tab_init[dim-1][k];
    }
    

    for (int h=dim-2; h>=0; h--){
        for (int f=0; f<=h; f++){
            tab[h][f]=max(tab_init[h][f]+tab[h+1][f], tab_init[h][f]+tab[h+1][f+1]);
        }
    }

    /*printf("\n");
    for (int k=0; k<dim; k++){
        for (int l=0; l<dim; l++){
                printf("%i ", tab[k][l]);
        }
        printf("\n");
    }*/

    res=tab[0][0];
    printf("\n%li\n", res);
    return 0;
}