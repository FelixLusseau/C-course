#include "encoder.h"

#include <string.h>
#include <stdlib.h>


int isFileBMP(FILE * file) 
{
    char key[2];
    fread(key, 1, 2, file);

    return key[0] == 'B' && key[1] == 'M';
}

void encode_byte(FILE * in, uint8_t c)
{
    uint8_t pixel;

    for(int bi = 0; bi < 8; bi++)
    {    
        fread(&pixel, 1, 1, in);
        pixel = (pixel & 0b11111110) | ((c & (1 << bi)) >> bi);
        fseek(in, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, in);
    }
}


uint8_t decode_byte(FILE * in) 
{
    uint8_t pixel;
    uint8_t byte = 0;

    for(int bi = 0; bi < 8; bi++)
    {    
        fread(&pixel, 1, 1, in);
        byte = byte | ((pixel & 0b1) << bi);
    }
    return byte;
}

void seekPixelArray(FILE *in) 
{
    uint32_t pixel_offset;
    fseek(in, 10, SEEK_SET);
    fread(&pixel_offset, 4, 1, in);
    fseek(in, pixel_offset, SEEK_SET);
}

uint32_t getDataSize(FILE *in) {
    uint32_t dataSize;
    fseek(in, 34, SEEK_SET);
    fread(&dataSize, 4, 1, in);
    return dataSize;
}

error_type_t encode(FILE*in, const char *message, uint64_t length) 
{

    if(!isFileBMP(in)) return ERROR_WRONG_INPUT_FORMAT;

    if((length+8)*8 > getDataSize(in)) {
        return ERROR_MESSAGE_TOO_LONG;
    }

    seekPixelArray(in);

    for(uint32_t i = 0; i < 8; i++) {
        encode_byte(in, (length >> (8*i)) & 0xFF);
    }

    for(uint32_t i = 0; i < length; i++) {
        encode_byte(in, message[i]);
    }
    return ENCODER_OK;

}

error_type_t decode(FILE*in, char **message, uint64_t *length)
{

    if(!isFileBMP(in)) return ERROR_WRONG_INPUT_FORMAT;

    seekPixelArray(in);

    // retrieve the lenght of the message
    for(uint64_t i = 0; i < 8; i++) {
        *length = *length | (decode_byte(in) << (8*i));
    }

    // alloc the memory to store the message
    *message = malloc(*length + 1);
    (*message)[*length] = '\0';

    // retrieve the message
    for(uint64_t i = 0; i < *length; i++) {
        (*message)[i] = decode_byte(in);
    }

    return ENCODER_OK;
}

