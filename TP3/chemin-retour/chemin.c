# include <stdio.h>

int main(){
    int n;
    scanf("%i", &n);
    int tab[n];
    for (int i=0; i<n; i++){
        scanf("%i", &tab[i]);
    }
    int tabret[n];
    for (int j=1; j<=n; j++){
        switch (tab[j-1])
        {
        case 1:
            tabret[n-j]=2;
            break;
        case 2:
            tabret[n-j]=1;
            break;
        case 3:
            tabret[n-j]=3;
            break;
        case 4:
            tabret[n-j]=5;
            break;
        case 5:
            tabret[n-j]=4;
            break;
        }
    }
    for (int k=0; k<n; k++)
        printf("%i\n", tabret[k]);
    return 0;
}