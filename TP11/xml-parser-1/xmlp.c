#include <stdio.h>
#include "xmlp.h"
#include <stdlib.h>

parser_error_type_t parse(const char *filename, parser_info_t *info){
    int c;
    FILE * file = fopen(filename, "r");
    if (file == NULL)
        return ERROR_UNABLE_TO_OPEN_FILE;
    char * buffer = malloc(1000);
    if (buffer==NULL)
        return 12;
    while ((c=fgetc(file))!=EOF){
        //printf("carac : %c\n", (char)c);
        chevron: if (c=='<'){
            int i = 0;
            while ((c=fgetc(file))!='>'){
                //printf("carac if : %c\n", (char)c);
                if (c==EOF){
                    free(buffer);
                    fprintf(stderr, "Unexpected end of tag (missing '>')");
                    return ERROR_UNEXPECTED_END_OF_TAG;
                }
                buffer[i]=c;
                i++;
                if (c==' '){
                    while (c!='>'){
                        c=fgetc(file);
                    }
                    break;
                }
            }
            buffer[i]='\0';
            //printf("tag : %s\n", buffer);
            if (buffer[0]!='/')
                info->handleOpenTag(buffer, info->data);
            else
                info->handleCloseTag(&buffer[1], info->data);
            c=fgetc(file);
        }
        if (c==EOF)
            continue;
        if (c!='<'){
            buffer[0]=c;
            int i = 1;
            while ((c = fgetc(file)) != '<')
            {
                //printf("carac else : %c\n", (char)c);
                if (c == EOF)
                {
                    free(buffer);
                    return PARSER_OK;
                }
                //printf("carac : %c\n", (char)c);
                buffer[i] = c;
                i++;
            }
            buffer[i] = '\0';
            //printf("text : %s\n", buffer);
            info->handleText(buffer, info->data);
            goto chevron;
        }
    }
    free(buffer);
    fclose(file);
    return PARSER_OK;
}