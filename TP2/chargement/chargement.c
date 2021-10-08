#include <stdio.h>

void progressBar(int n)
{
    printf("[");
    for (int i=1;i<=n;i++)
    {
        printf("=");
    }
    for (int i=n;i<10;i++)
    {
        printf(" ");
    }
    printf("]");
}

int main() {
    int n;
    /* printf("Entrez un nombre : \n"); */
    scanf("%i", &n);
    
    if (n<0)
    {
        progressBar(0);
    }
    if (n>10)
    {
        progressBar(10);
    }
    if (n>=0 && n<=10)
    {
        progressBar(n);
    }
    return 0;
}