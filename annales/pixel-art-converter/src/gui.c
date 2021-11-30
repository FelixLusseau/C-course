
#include "gui.h"


void render_gui(image_t* image)
{
    tps_createWindow("Image", image->width, image->height);
    while(tps_isRunning()) {
        tps_background(255,255,255);
        for(unsigned row = 0; row < image->height; row++)
        {
            for(unsigned int col = 0; col < image->width; col++)
            {
                uint8_t bleu = image->pixels[row*image->width + col] & 0xFF;
                uint8_t vert = (image->pixels[row*image->width + col] & 0xFF00) >> 8;
                uint8_t rouge = (image->pixels[row*image->width + col] & 0xFF0000) >> 16;
                tps_setColor(rouge, vert, bleu);
                tps_drawPoint(col, image->height - row - 1);
            }
        }
        tps_render();
    }
    tps_closeWindow();
}