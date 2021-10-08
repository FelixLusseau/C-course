#include <stdio.h>

int main()
{
    int h;
    // printf("Hauteur ? \n");
    scanf("%i", &h);
    if (h<=0)
    {
        printf("IMPOSSIBLE");
    }
    else{
    for (int i=1; i<=h; i++)
    {
        int j=h+1-i;
        for (int l=1; l<j; l++)
        {
            printf(" ");
        }
        for (int k=1;k<=i+1;k++)
        {
            printf("#");
        }
        printf("\n");
    }
    }
    return 0;
}