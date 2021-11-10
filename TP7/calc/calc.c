# include <stdio.h>
# include "parser.h"
# include "calc-io.h"

int main(void){
    printf("Entrez un calcul dans le format : X operation Y\n");
    char chaine[100];
    fgets(chaine, 100, stdin);
    /*for (int i=0; i<4; i++)
            printf("chaine '%c'\n", *chaine[i]);*/
    double a, b;
    char op;
    int corr = parse(chaine, &a, &b, &op);
    //printf("parse return : %i\n", corr);
    //printf("test %f %c %f", a, op, b);
    if (corr == PARSE_OK){
        //printf("OK\n");
        printResult(a, b, op);
        return corr;
    }
    else
        return corr;
    
}