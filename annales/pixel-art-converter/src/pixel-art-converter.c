#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/errno.h>
#include <ctype.h>
#include <unistd.h>

#include "bmp-io.h"
#include "filter.h"
#include "gui.h"
#include "utils.h"


int main(int argc, char ** argv)
{
    actions_t actions;

    parse_args(argc, argv, &actions);

    if(actions.path == NULL)
    {
        fprintf(stderr, "Il manque l'option -i suivie du nom du fichier à ouvrir\n");
        print_usage();
        return 1;
    }

    image_t *image = open_bmp(actions.path);
    if(image->error != NULL) goto error;

    if(actions.debug)
    {
        print_headers(image);
    }

    if(actions.with_filter) 
    {
        apply_filter(image);
    }

    if(actions.with_ui)
    {
        render_gui(image);
    }

    //printf("%s\n", actions.out_format);
    if(actions.output_path && strcmp(actions.out_format,"BMP")==0)
    {
        save_bmp(image, actions.output_path);
    }

    if(actions.output_path && strcmp(actions.out_format,"PATF")==0)
    {
        save_patf(image, actions.output_path);
    }

    close_image(image);
    return 0;



    error:
    if(image && image->error)
    {
        fprintf(stderr, "%s\n", image->error);
    }
    close_image(image);
    return 1;

}