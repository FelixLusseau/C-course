#ifndef ARGS_PARSER_H
#define ARGS_PARSER_H
#include <stdio.h>
#include <inttypes.h>

typedef enum action_t {
    ACTION_UNKNOWN,
    ACTION_ENCODE,
    ACTION_DECODE
} action_t;

/**
 * @brief Options that can be sent in the command line
 * 
 */
typedef struct options_t {
    action_t action;
    char *inputFilename;
    char *outputFilename;
    char *messageToEncode;
    uint64_t messageLength;
    uint32_t compressionRate;

    FILE *inputFile;
    FILE *outputFile;
} options_t;

void printUsage(void);

void parseArgs(int argc, char **argv, options_t *options);


void cleanOptions(options_t *options);

#endif