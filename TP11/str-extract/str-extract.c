# include "str-extract.h"
# include <stdio.h>

void strExtract(FILE *in, char *delim, char *buffer, size_t size){
    while (1){
        for (int i = 0; i<(int)size; i++){
            buffer[i]=fgetc(in);
            if (buffer[i]==EOF){
                buffer[i]='\0';
                fprintf(stderr, "%s\n", buffer);
                return;
            }
            if (buffer[i]==*delim){
                buffer[i]='\0';
                printf("%s\n", buffer);
                fseek(in, -1, SEEK_CUR);
                return;
            }
        }
    }
}