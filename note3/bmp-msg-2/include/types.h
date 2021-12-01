
#ifndef TYPES_HEADER
#define TYPES_HEADER

typedef enum error_type_t {
    ENCODER_OK,
    ERROR_OPENING_FILES,
    ERROR_WRONG_INPUT_FORMAT,
    ERROR_MESSAGE_TOO_LONG,
    DECODER_MAGIC_ERROR
} error_type_t;

#endif
