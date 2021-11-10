int parse(const char * line, double *a, double *b, char *op);

typedef enum parseres{
    PARSE_OK,
    PARSE_ERROR_FORMAT,
    PARSE_ERROR_OPERATION
} parseres;