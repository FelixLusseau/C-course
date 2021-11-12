# include <stdio.h>
#include <tps_stack.h>

int main(){
    tps_stack pile = tps_stack_create();
    int mvt;
    while (1){
        scanf("%i", &mvt);
        tps_stack_push(pile, mvt);
        if (mvt==0)
            break;
    }    
    int size_pile=tps_stack_size(pile);
    //printf("%i\n", size_pile);
    for (int i=0; i<size_pile; i++){
        switch (tps_stack_pop(pile))
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
    tps_stack_free(pile);
    return 0;
}