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
    int count=0;
    int k=0;
    while (str[k] != '\0'){
        if (str[k]=='A')
        {
            count+=1;
        }
        k++;
    }
    printf("%i\n", count);
    return 0;
}