
#ifndef BMP_IO_H
#define BMP_IO_H

#include "image.h"

typedef struct actions_t {
    int debug;
    int with_filter;
    int with_ui; 
    char * path;
    char * output_path;
    char * out_format;
} actions_t;

void print_usage(void);

int parse_args(int argc, char ** argv, actions_t * actions);

// DIB header size define the type of header
// used by the image

#define BITMAPINFOHEADER_SIZE 40 
#define BITMAPV2INFOHEADER_SIZE 52 
#define BITMAPV3INFOHEADER_SIZE 56 
#define BITMAPV4INFOHEADER_SIZE 108 
#define BITMAPV5INFOHEADER_SIZE 124 



// The two kind of compression that we handle
#define COMPRESSION_BI_RGB 0
#define COMPRESSION_BI_BITFIELDS 3

int is_bmp(FILE * in);

/**
 * Retourne un structure image qui contient les informations sur l'image
 * (voir structure image_t). Si l'attribut erreur est non NULL alors la lecture 
 * a échouée et error contient le message d'erreur.
 * 
 * La structure doit être libérée avec close_image dans tous les cas
 */
image_t *open_bmp(const char * path);

/**
 * libère la structure
 */
void close_image(image_t*image);

/**
 * permet de sauvegarder l'image contenu dans la structure image
 * à l'emplacement path, au format bmp.
 */
int save_bmp(image_t* image, char *path);

int save_patf(image_t * image, char * path);

#endif