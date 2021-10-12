#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int i=1; i<argc; i++)
    {
        char *str=argv[i];
        for (int k = 0; str[k]!='\0'; k++) {
            if(str[k] >= 'a' && str[k] <= 'z') {
                str[k] = str[k] - 32;
            }
        }
    printf("%s\n", str);
    }
    return 0;
}