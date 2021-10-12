#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    int count=0;
    fgets(str, 1000, stdin);
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