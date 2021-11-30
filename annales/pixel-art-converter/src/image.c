
#include "image.h"
#include "bmp-io.h"

#include <stdlib.h>

image_t * init_image(void) {
    image_t *image = calloc(1, sizeof(image_t));
    if(image==NULL) {
        fprintf(stderr, "Allocation error in init_image()");
        return NULL;
    }


    // default pixel mask
    image->red_mask   = 0xFF0000;
    image->green_mask = 0xFF00;
    image->blue_mask  = 0xFF;
    image->red_shift = 16;
    image->green_shift = 8;
    image->blue_shift = 0;

    return image;
}

color_rgb_t pixel_2_color(image_t *image, uint32_t pixel)
{
    color_rgb_t c;
    c.r = (pixel & image->red_mask) >> image->red_shift;
    c.g = (pixel & image->green_mask) >> image->green_shift;
    c.b = (pixel & image->blue_mask) >> image->blue_shift;
    return c;
}

uint32_t rgb_2_pixel(image_t *image, unsigned char r, unsigned char g, unsigned char b)
{
    return (((uint32_t)r) << image->red_shift)
        + (((uint32_t)g) << image->green_shift)
        + (((uint32_t)b) << image->blue_shift);
}

uint32_t color_2_pixel(image_t *image, color_rgb_t c)
{
    return rgb_2_pixel(image, c.r, c.g, c.b);
}
