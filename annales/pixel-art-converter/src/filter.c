
#include "filter.h"


int compar_pixel(const void * p1_p, const void * p2_p)
{
    long long p1 = *(uint32_t*)p1_p;
    long long p2 = *(uint32_t*)p2_p;
    
    return p2 - p1;
}


void apply_filter(image_t* image)
{
    for(unsigned row = 0; row < image->height; row++)
    {
        for(unsigned int col = 0; col < image->width; col++)
        {
            color_rgb_t c = pixel_2_color(image, image->pixels[row*image->width + col]);
            int sum = c.r;
            sum += c.g; 
            sum += c.b;
            sum /= 3;
            c.r = c.g = c.b = sum; 
            image->pixels[row*image->width + col] = color_2_pixel(image, c);
        }
    }
}