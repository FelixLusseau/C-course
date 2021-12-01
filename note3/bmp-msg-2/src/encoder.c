#include "encoder.h"

#include <string.h>
#include <stdlib.h>


int isFileBMP(FILE * file) 
{
    char key[2];
    fread(key, 1, 2, file);

    return key[0] == 'B' && key[1] == 'M';
}

void encode_byte(FILE * in, uint8_t c, uint32_t compressionRate)
{
    uint8_t pixel;

    if (compressionRate==1){
        for(int bi = 0; bi < 8; bi++)
        {    
            fread(&pixel, 1, 1, in);
            pixel = (pixel & 0b11111110) | ((c & (1 << bi)) >> bi);
            fseek(in, -1, SEEK_CUR);
            fwrite(&pixel, 1, 1, in);
        }
    }
    if (compressionRate==2){
        for(int bi = 0; bi <= 6; bi+=2)
        {    
            fread(&pixel, 1, 1, in);
            pixel = (pixel & 0b11111100) | ((c & (0b11 << bi)) >> bi);
            fseek(in, -1, SEEK_CUR);
            fwrite(&pixel, 1, 1, in);
        }
    }
    if (compressionRate==4){
        for(int bi = 0; bi <= 4; bi+=4)
        {    
            fread(&pixel, 1, 1, in);
            pixel = (pixel & 0b11110000) | ((c & (0b1111 << bi)) >> bi);
            fseek(in, -1, SEEK_CUR);
            fwrite(&pixel, 1, 1, in);
        }
    }
}


uint8_t decode_byte(FILE * in, uint32_t compressionRate) 
{
    uint8_t pixel;
    uint8_t byte = 0;

    if (compressionRate==1){
        for(int bi = 0; bi < 8; bi++)
        {    
            fread(&pixel, 1, 1, in);
            byte = byte | ((pixel & 0b1) << bi);
        }
    }
    if (compressionRate==2){
        for(int bi = 0; bi <= 6; bi+=2)
        {    
            fread(&pixel, 1, 1, in);
            byte = byte | ((pixel & 0b00000011) << bi);
        }
    }
    if (compressionRate==4){
        for(int bi = 0; bi <= 4; bi+=4)
        {    
            fread(&pixel, 1, 1, in);
            byte = byte | ((pixel & 0b00001111) << bi);
        }
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
    if (dataSize==0){
        fseek(in, 28, SEEK_SET);
        uint16_t bitsPerPixel; 
        fread(&bitsPerPixel, 2, 1, in);
        int32_t width, height;
        fseek(in, 18, SEEK_SET);
        fread(&width, 4, 1, in);
        fseek(in, 22, SEEK_SET);
        fread(&height, 4, 1, in);
        dataSize = (uint32_t)(((bitsPerPixel*width+31)/32)*4*height);
    }
    //printf("datasize : %i\n", dataSize);
    return dataSize;
}

error_type_t encode(FILE*in, const char *message, uint64_t length, uint32_t compressionRate) 
{

    if(!isFileBMP(in)) return ERROR_WRONG_INPUT_FORMAT;

    if((length/compressionRate+8+4+4)*8 > getDataSize(in)) {
        return ERROR_MESSAGE_TOO_LONG;
    }

    seekPixelArray(in);

    for(uint32_t i = 0; i < 4; i++){
        encode_byte(in, (0b10101010 >> (4*i)) & 0x7F, 1);
    }

    for(uint32_t i = 0; i < 8; i++) {
        encode_byte(in, (length >> (8*i)) & 0xFF, 1);
    }

    for(uint32_t i = 0; i < 4; i++){
        encode_byte(in, (compressionRate >> (4*i)) & 0x7F, 1);
    }
    printf("Progression : \n");
    for(uint32_t i = 0; i < length; i++) {
        encode_byte(in, message[i], compressionRate);
        printf("\r%li%%", i*100/length);
    }
    printf("\r100%% ! \n");
    return ENCODER_OK;

}

error_type_t decode(FILE*in, char **message, uint64_t *length)
{

    if(!isFileBMP(in)) return ERROR_WRONG_INPUT_FORMAT;

    seekPixelArray(in);

    uint8_t magic=0;
    // retrieve the magic pixels of the message
    for(uint64_t i = 0; i < 4; i++) {
        magic = magic | (decode_byte(in, 1) << (4*i));
    }
    //printf("magic : %i\n", magic);
    if (magic!=0b10101010)
        return DECODER_MAGIC_ERROR;

    // retrieve the lenght of the message
    for(uint64_t i = 0; i < 8; i++) {
        *length = *length | (decode_byte(in, 1) << (8*i));
    }

    uint32_t compressionRate=0;
    // retrieve the magic pixels of the message
    for(uint64_t i = 0; i < 4; i++) {
        compressionRate = compressionRate | (decode_byte(in, 1) << (4*i));
    }

    // alloc the memory to store the message
    *message = malloc(*length + 1);
    (*message)[*length] = '\0';

    // retrieve the message
    for(uint64_t i = 0; i < *length; i++) {
        (*message)[i] = decode_byte(in, compressionRate);
    }

    return ENCODER_OK;
}

