
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdint.h>

/**
 * Structure stockant les information d'une image
 * les infos peuvent être générique (hauteur, largeur, pixels)
 * ou spécifique au format BMP
 */
typedef struct image_t {
    const char *error;
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;

    // Attributs spécifique aux fichier BMP
    uint32_t size;
    uint32_t offset;
    uint16_t color_depth;
    uint32_t compression_method;
    uint32_t DIB_header_size;
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint32_t alpha_mask;
    uint32_t red_shift;
    uint32_t green_shift;
    uint32_t blue_shift;
    uint32_t alpha_shift;
} image_t;

/**
 * structure stockant les composantes rouge/vert/bleu d'un pixel
 */
typedef struct color_rgb_t {
    unsigned char r, g, b;
} color_rgb_t;


/** Alloue et initialise la strucutre image avec
 * les information essentielles pour l'utilisations des fonctions suivantes
 */
image_t * init_image(void);

/**
 * Permet de convertir un pixel issue du tableau de pixel d'une image
 * en structure color_rgb_t (afin de récupérer facilement les composantes rouge/vert/bleu)
 * */
color_rgb_t pixel_2_color(image_t *image, uint32_t pixel);


/**
 * Permet d'obtenir la valeur d'un pixel (utilisable dans le tableau de pixel d'une image)
 * à partir des composantes rouge/vert/bleu.
 * */
uint32_t rgb_2_pixel(image_t *image, unsigned char r, unsigned char g, unsigned char b);

/**
 * Permet d'obtenir la valeur d'un pixel (utilisable dans le tableau de pixel d'une image)
 * à partir d'une structure color_rgb_t
 * */
uint32_t color_2_pixel(image_t *image, color_rgb_t c);




#endif