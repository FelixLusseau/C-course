# include <stdio.h>
# include <math.h>

int main(int argc, char ** argv){
    if (argc<3){
        fprintf(stderr, "Il faut entrer ./convert FICHIER-D'ENTREE FICHIER-DE-SORTIE\n");
        return 1;
    }
    FILE * in = fopen(argv[1], "r");
    if (in == NULL)
        return 1;
    FILE * out = fopen(argv[2], "w");
    if (out == NULL)
        return 1;
    float degc;
    float degf;
    while (fscanf(in, "%f", &degc)!=EOF){
        degf=(degc*9/5)+32;
        fprintf(out, "%.2f\n", degf * 100 / 100);
    }
    return 0;
}