#include <stdio.h>

int main(){
    int temp, nb, min, max;
    scanf("%i", &nb);
    scanf("%i", &min);
    scanf("%i", &max);
    for (int i=1; i<=nb; i++)
    {
        scanf("%i", &temp);
        if (temp>=min && temp<=max)
            printf("Rien à signaler\n");
        else{
            printf("Alerte !!\n");
            break;
        }
    }
    return 0;
}