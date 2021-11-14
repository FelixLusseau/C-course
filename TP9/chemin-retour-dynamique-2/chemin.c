#include <stdio.h>
#include <tps_stack.h>
#include <stdlib.h>

int main()
{
    int *tab = malloc(10005 * sizeof(int));
    if (tab == NULL)
        return 1;
    int i = 0;
    while (1)
    {
        scanf("%i", &tab[i]);
        if (tab[i] == 0)
        {
            
            break;
        }
        i++;
    }
    for (int j = i; j>=0; j--)
    {
        switch (tab[j])
            {
            case 1:
                printf("2\n");
                break;
            case 2:
                printf("1\n");
                break;
            case 3:
                printf("3\n");
                break;
            case 4:
                printf("5\n");
                break;
            case 5:
                printf("4\n");
                break;
            }
    }
    free(tab);
    return 0;
}