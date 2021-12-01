#include "io-utils.h"
#include "types.h"

#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

void copy_file(FILE*in, FILE*out) {
    char buffer[1000];
    long nb = 0;
    while((nb = fread(buffer, 1, 1000, in)) != 0) {
        fwrite(buffer, 1, nb, out);
    }
}

error_type_t openFiles(options_t * options) {
    options->inputFile = fopen(options->inputFilename, "r");

    if(options->inputFile == NULL) {

        fprintf(stderr,"Error while opening the input file '%s': %s", options->inputFilename, strerror(errno));
        return ERROR_OPENING_FILES;
    }

    if(options->outputFilename != NULL) {
        options->outputFile = fopen(options->outputFilename, "w+");

        if(options->outputFile == NULL) {
            
            fprintf(stderr,"Error while opening the output file '%s': %s", options->outputFilename, strerror(errno));
            return ERROR_OPENING_FILES;
        }

        copy_file(options->inputFile, options->outputFile);
        fseek(options->outputFile, 0, SEEK_SET);
    }
    return ENCODER_OK;
}



const char * errorToString(error_type_t err) 
{
    switch(err) {
        case ERROR_OPENING_FILES: return "Error while opening files";
        case ERROR_WRONG_INPUT_FORMAT: return "The input file is not a BMP image";
        case ERROR_MESSAGE_TOO_LONG: return "The message is too long and cannot fit in the given image";
        case DECODER_MAGIC_ERROR: return "This image doesn't contain an encoded message or it is erroneous";
        default:
        case ENCODER_OK: return "";
    }
}