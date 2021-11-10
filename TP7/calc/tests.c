#include "calc-io.h"
#include "parser.h"
#include <stdio.h>

int main(void) {
    double a, b;
    char op;
    //printf("%i %i\n", parse("5 5 6", &a, &b, &op), PARSE_ERROR_OPERATION);
    if(parse("5 5 6", &a, &b, &op) != PARSE_ERROR_OPERATION) {
        fprintf(stderr, "parse(\"5 5 6\") doit renvoyer une erreur PARSE_ERROR_OPERATION\n");
        return 1;
    }
    if(parse("5 a 6", &a, &b, &op) != PARSE_ERROR_OPERATION) {
        fprintf(stderr, "parse(\"5 a 6\") doit renvoyer une erreur PARSE_ERROR_OPERATION\n");
        return 1;
    }
    if(parse("5", &a, &b, &op) != PARSE_ERROR_FORMAT) {
        fprintf(stderr, "parse(\"5\") doit renvoyer une erreur PARSE_ERROR_FORMAT\n");
        return 1;
    }
    if(parse("5 a", &a, &b, &op) != PARSE_ERROR_FORMAT) {
        fprintf(stderr, "parse(\"5 a\") doit renvoyer une erreur PARSE_ERROR_FORMAT\n");
        return 1;
    }
    if(parse("5 6", &a, &b, &op) != PARSE_ERROR_FORMAT) {
        fprintf(stderr, "parse(\"5 6\") doit renvoyer une erreur PARSE_ERROR_FORMAT\n");
        return 1;
    }
    if(parse("5 +/6", &a, &b, &op) != PARSE_ERROR_FORMAT) {
        fprintf(stderr, "parse(\"5 +/6\") doit renvoyer une erreur PARSE_ERROR_FORMAT\n");
        return 1;
    }
    if(parse("5 + -6", &a, &b, &op) != PARSE_OK) {
        fprintf(stderr, "parse(\"5 +-6\") doit renvoyer PARSE_OK\n");
        return 1;
    }
    printResult(10.0, 50.1, '+');
    return 0;
}
