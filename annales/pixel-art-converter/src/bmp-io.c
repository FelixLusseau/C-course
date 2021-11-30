
#include "bmp-io.h"
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


void load_pixels(image_t* image, FILE* in);
void load_headers(image_t * image, FILE* in);

void print_usage(void)
{
    printf("usage: ./fichier OPTIONS\n"
    "options:\n"
    "\t-i FICHIER    indiquer le fichier à ouvrir\n"
    "\t-o FICHIER    indiquer le fichier ou est sauvegarder le résultat\n"
    "\t-u            afficher l'image dans une fenêtre\n"
    "\t-f            application de la fonction de filtre\n"
    "\t-d            afficher le debug\n\n\n"
    "Exemples:\n"
    "./fichier -i image.bmp -d -f -u -o image_out.bmp\n");
}

int parse_args(int argc, char ** argv, actions_t * actions){
    char c;
    actions->debug = 0;
    actions->with_filter = 0;
    actions->with_ui = 0; 
    actions->path = NULL;
    actions->output_path = NULL;
    actions->out_format = NULL;
    while ((c = getopt (argc, argv, "hi:fduo:t:")) != -1)
    {
        switch (c)
        {
            case 'h':
                print_usage();
                return 0;
            case 'd':
                actions->debug = 1;
                break;
            case 'u':
                actions->with_ui = 1;
                break;
            case 'f':
                actions->with_filter = 1;
                break;
            case 'i':
                actions->path = optarg;
                break;
            case 'o':
                actions->output_path = optarg;
                if (actions->out_format==NULL)
                    actions->out_format="BMP";
                break;
            case 't':
                if (strcmp(optarg,"")==0 || strcmp(optarg,"BMP")==0)
                    actions->out_format="BMP";
                if (strcmp(optarg,"PATF")==0)
                    actions->out_format="PATF";
                //fprintf(stderr, "arg format : %s\n", actions->out_format);
                break;
            case '?':
                if (optopt == 'i')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);

                print_usage();

                return 1;
        }
    }
    return 0;
}

int is_bmp(FILE * in){
    char first_bytes[2];
    fread(first_bytes, 1, 2, in);
    rewind(in);
    return first_bytes[0] == 'B' && first_bytes[1] == 'M';
}

image_t *open_bmp(const char * path)
{
    image_t *image = init_image();
    if(image == NULL)
    {
        return NULL;
    }

    FILE *in = fopen(path, "r+b");
    if(in == NULL)
    {
        image->error = strerror(errno);
        goto error;
    }

    if (!is_bmp(in)){
        image->error = "It is not a BMP image !";
        goto error;
    }

    load_headers(image, in);
    if(image->error != NULL) goto error;
    
    load_pixels(image, in);
    if(image->error != NULL) goto error;


    error:
    if(in) fclose(in);
    return image;
}



void load_pixels(image_t* image, FILE* in)
{
    fseek(in, image->offset, SEEK_SET);
    image->pixels = malloc(image->width * image->height * sizeof(image->pixels[0]));
    if(image->pixels == NULL)
    {
        image->error = "Problème d'allocation mémoire";
        return;
    }

    unsigned row_padding = 0;
    if((image->width*3) % 4) row_padding = 4 - ((image->width*3) % 4);

    for(uint32_t row = 0; row < image->height; row++)
    {
        for(uint32_t col = 0; col < image->width; col++)
        {
            if(0 == fread(&image->pixels[row*image->width + col], 3, 1, in))
            {
                image->error = "Problème de format lors de la lecture des pixels";
                return;
            }
        }
        fseek(in, row_padding, SEEK_CUR);
    }

}


void load_headers(image_t * image, FILE* in)
{
    fseek(in, 2, SEEK_CUR);
    fread(&image->size, 4, 1, in);

    fseek(in, 4, SEEK_CUR);
    fread(&image->offset, 4, 1, in);

    fseek(in, 14, SEEK_SET);
    fread(&image->DIB_header_size, 2, 1, in);
    if(image->DIB_header_size != BITMAPINFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV2INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV3INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV4INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV5INFOHEADER_SIZE)
    {
        fprintf(stderr, "DIB header size: %u\n", image->DIB_header_size);
        image->error = "The header is not of type BITMAPV*INFOHEADER";
        return;
    }


    fseek(in, 18, SEEK_SET);
    fread(&image->width, 4, 1, in);
    fread(&image->height, 4, 1, in);

    fseek(in, 28, SEEK_SET);
    fread(&image->color_depth, 2, 1, in);
    if(image->color_depth != 24)
    {
        image->error = "We currently only support a color depth of 24";
        return;
    }

    fseek(in, 30, SEEK_SET);
    fread(&image->compression_method, 4, 1, in);

    switch(image->compression_method) {
        case COMPRESSION_BI_RGB:
            image->red_mask   = 0xFF0000;
            image->green_mask = 0xFF00;
            image->blue_mask  = 0xFF;
            image->red_shift = 16;
            image->green_shift = 8;
            image->blue_shift = 0;
        break;
        case COMPRESSION_BI_BITFIELDS:
            fseek(in, 30, SEEK_SET);
            fread(&image->red_mask, 4, 1, in);
            fread(&image->green_mask, 4, 1, in);
            fread(&image->blue_mask, 4, 1, in);

            // TODO: compute that dynamically
            image->red_shift = 16;
            image->green_shift = 8;
            image->blue_shift = 0;
            image->alpha_shift = 0;

            if(image->color_depth == 32)
            {
                fread(&image->alpha_mask, 4, 1, in);
            }
        break;
        default:
        image->error = "Compression method no supported";
    }
}



void close_image(image_t*image)
{
    if(image) {
        free(image->pixels);
    }
    free(image);
}



int save_bmp(image_t* image, char *path)
{
    FILE *out = fopen(path, "wb");
    if(out == NULL) return 0;
    
    fwrite("BM", 2, 1, out);

    uint32_t tmp_word = 0;
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // Size (put 0 and come back lated to enter the size)
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // application specific
    tmp_word = 54;
    fwrite(&tmp_word, 4, 1, out); // offset
    tmp_word = 40;
    fwrite(&tmp_word, 4, 1, out); // DIB header size

    tmp_word = image->width;
    fwrite(&tmp_word, 4, 1, out); 
    tmp_word = image->height;
    fwrite(&tmp_word, 4, 1, out); 

    tmp_word = 1;
    fwrite(&tmp_word, 2, 1, out);  // plane	Number of color planes being used
    tmp_word = 24;
    fwrite(&tmp_word, 2, 1, out); // Number of bits per pixel
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // BI_RGB, no pixel array compression used
    tmp_word = 16;
    fwrite(&tmp_word, 4, 1, out); // Size of the raw bitmap data (including padding)
    tmp_word = 2835;
    fwrite(&tmp_word, 4, 1, out); // pixels/metre horizontal	Print resolution of the image,
    tmp_word = 2835;
    fwrite(&tmp_word, 4, 1, out); // pixels/metre vertical	Print resolution of the image,
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // Number of colors in the palette
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // important colors	0 means all colors are important


    unsigned row_padding = 0;
    if((image->width*3) % 4) row_padding = 4 - ((image->width*3) % 4);

    for(uint32_t row = 0; row < image->height; row++)
    {
        for(uint32_t col = 0; col < image->width; col++)
        {
            if(0 == fwrite(&image->pixels[row*image->width + col], 3, 1, out))
            {
                fclose(out);
                return 0;
            }
        }
        fwrite(&tmp_word, row_padding, 1, out);
    }

    tmp_word = ftell(out); // get size;
    fseek(out, 2, SEEK_SET); // go back at the beginning to write the size
    fwrite(&tmp_word, 4, 1, out);

    fclose(out);
    return 1;
}

int save_patf(image_t * image, char * path){
    FILE *out = fopen(path, "w");
    if(out == NULL) return 0;
    
    fprintf(out, "PATF\n");
    fprintf(out, "%i %i\n", image->width, image->height);
    fprintf(out, "1\n");
    fprintf(out, "@: 0 0 0\n%%: 2 2 2\n#: 4 4 4\n+: 8 8 8\n=: 16 16 16\n-: 32 32 32\n:: 64 64 64\n.: 128 128 128\n");
    fprintf(out, "-\n");
    int imin=0;
    for(unsigned row = image->height-1 ; row>0; row--)
    {
        for(unsigned int col = 0; col<image->width; col++)
        {
            imin=128;
            color_rgb_t c = pixel_2_color(image, image->pixels[row*image->width + col]);
            int sum = c.r;
            sum += c.g; 
            sum += c.b;
            sum /= 3;
            //fprintf(stderr, "r : %i g : %i b : %i\n", c.r, c.g, c.b);
            for (int i=128; i>=1; i/=2){
                //fprintf(stderr, "i : %i\n", i);
                //fprintf(stderr, "calc : %i\n", abs(sum-i));
                if (abs(sum-i)<imin){
                    imin=i;
                }
                //fprintf(stderr, "imin : %i\n", imin);
            }
            switch (imin)
            {
            case 0:
                fprintf(out, "@");
                break;
            case 2:
                fprintf(out, "%%");
                break;
            case 4:
                fprintf(out, "#");
                break;
            case 8:
                fprintf(out, "+");
                break;
            case 16:
                fprintf(out, "=");
                break;
            case 32:
                fprintf(out, "-");
                break;
            case 64:
                fprintf(out, ":");
                break;
            case 128:
                fprintf(out, ".");
                break;
            default:
                break;
            }
        }
        fprintf(out, "\n");
    }
    fclose(out);
    return 1;
}
