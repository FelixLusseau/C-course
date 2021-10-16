#include <stdio.h>

int main(){
    int n;
    scanf("%i", &n);
    if (n<=1)
        printf("IMPOSSIBLE\n");
    else
    {
    int c=n;
    for (int i=1; i<=n; i++)
        printf("_");
    printf("\n");
    for (int j=2; j<=n; j++)
    {
        for (int l=1; l<c; l++)
        {
            printf(" ");
        }
        printf("/\n");
        c--;
    }
    printf("/");
    for (int k=1; k<=n-1; k++)
        printf("_");
    printf("\n");
    }
}