#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
    if (argc<3)
        exit(42);
    char * D = argv[1];
    char * H = argv[2];
    if (atoi(D)<0 || atoi(H)<0)
        exit(42);
    //printf("%s\n", D);
    //printf("%s\n", H);
    int coutHm=9047;
    int coutDm=21534;
    int coutTotal = 0;
    int nbPilliers = 0;
    while (nbPilliers*72<=atoi(D)-72)
        nbPilliers++;
    coutTotal=nbPilliers*atoi(H)*coutHm+atoi(D)*coutDm;
    printf("%i\n", coutTotal);
    //printf("%i\n", atoi(D));
    return 0;
}