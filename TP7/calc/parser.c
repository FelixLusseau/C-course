# include "parser.h"
# include <stdio.h>
# include <stdlib.h>

int parse(const char * line, double *a, double *b, char *op){
    parseres res;
    /*for (int i=0; i<5; i++)
                printf("%d\n", line[i]);*/
    //printf("sscanf rep : %i\n", sscanf(line, "%lf %c %lf", a, op, b));
    if (sscanf(line, "%lf %c %lf", a, op, b) == 3){
        //printf("a op b : %f %c %f\n", *a, *op, *b);
        if (*op=='+' || *op=='-' || *op=='/' || *op=='*' || *op=='^'){
            /**a=line[0];
            *b=line[4];
            *op=line[2];*/
            //printf("a op b : %f %c %f\n", *a, *op, *b);
            res = PARSE_OK;
            return res;
        }
        else{
            res = PARSE_ERROR_OPERATION;
            return res;
        }
    }
    else{   
        res = PARSE_ERROR_FORMAT;
        return res;
    }
}