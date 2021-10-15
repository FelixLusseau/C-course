#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc<2)
        exit(42);
    char str[strlen(argv[1])];
    if (str==NULL)
        exit(42);
    strcpy(str,argv[1]);
    int lettre = 'a';
    int count=0;
    int k=0;
    for (int i=97; i<123; i++){
    while (str[k] != '\0'){
        if (str[k]==lettre || str[k]==lettre-32)
        {
            count+=1;
        }
        k++;
    }
    printf("%c:%i\n", (char)lettre, count);
    count=0;
    k=0;
    lettre+=1;
    }
    return 0;
}