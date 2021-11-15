#include <stdio.h>

void action(void)
{
    int m;
    scanf("%i", &m);
    if (m!=0)
    {
        action();
        switch (m)
        {
        case 4: printf("5\n"); break;
        case 5: printf("4\n"); break;
        case 1: printf("2\n"); break;
        case 2: printf("1\n"); break;
        case 3: printf("3\n"); break;
        }
    }
}

int main()
{
    action();
}