
#include "utils.h"



void print_headers(image_t *image)
{
    printf("image->size %u\n", image->size);
    printf("offset %u\n", image->offset);
    printf("color_depth %u\n", image->color_depth);
    printf("width x height %ux%u\n", image->width, image->height);
    printf("compression_method %u\n", image->compression_method);
    printf("DIB_header_size %u\n", image->DIB_header_size);
}