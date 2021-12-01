#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "args-parser.h"
#include "io-utils.h"
#include "encoder.h"


int actionDecode(options_t *options) {

    char * message = NULL;
    uint64_t length = 0;

    int exitCode = decode(
            options->inputFile, 
            &message,
            &length);

    if(exitCode == ENCODER_OK)
    {
        fwrite(message, 1, length, stdout);
        fwrite("\n", 1, 1, stdout);
        free(message);
    } 
    else 
    {
        fprintf(stderr, "error while decoding %i\n", exitCode);
    }
    return exitCode;
}

int actionEncode(options_t *options) {
    int exitCode = encode(
        options->outputFile, 
        options->messageToEncode,
        options->messageLength, options->compressionRate); 
    if(exitCode != ENCODER_OK) 
    {
        fprintf(stderr, "error while encoding %i\n", exitCode);
    }
    return exitCode;
}

int main(int argc, char **argv) {
    
    int exitCode = 0;

    options_t options;
    
    parseArgs(argc, argv, &options);

    if(ENCODER_OK != (exitCode = openFiles(&options))) {
        goto quit;
    }

    
    switch(options.action) {
        case ACTION_DECODE: 
            if (isFileTxt(options.inputFile)){ 
                char * message = NULL;
                uint64_t length = 0;
                exitCode = decodeTxt(options.inputFile, &message, &length);
                break;
            }
            exitCode = actionDecode(&options);
            break;
        case ACTION_ENCODE:
            if (isFileTxt(options.inputFile)){ 
                exitCode = encodeTxt(options.outputFile, options.messageToEncode, options.messageLength);
                break;
            }
            exitCode = actionEncode(&options);
            break;
        case ACTION_UNKNOWN:
            fprintf(stderr, "action is missing\n");
            exitCode = 4;
    }


    quit:

    if(exitCode) 
        fprintf(stderr, "%s\n", errorToString(exitCode));

    cleanOptions(&options);
    return exitCode;
}