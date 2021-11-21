#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARAC 1000

// Aération du code = faire des blocs "logiques"
// Ex : malloc et la vérif de la bonne allocation

void display_usage(char**); // Déclaration de fonction

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3) // Check du bon nb d'arg renforcé
    {
        display_usage(argv);
        return 1;
    }
    
    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
        return 2;

    FILE *out = NULL;
    if (argv[2] == NULL)
        //out = stderr; Pourquoi stderr ? La sortie standard est stdout.
        out = stdout;
    else
        out = fopen(argv[2], "w");
    if (out == NULL)
        return 3;
    
    //char *line = malloc(1000); 
    // Éviter de définir des constantes magiques (1000 ici)
    // car si on veut modifier 1000 en 10 000 000, il va falloir
    // modifier les lignes une à une.
    // '#define' à privilégier
    
    char *line = malloc(MAX_CARAC+1);
    if (line == NULL)
        return 4;
    
    char *line_indent = malloc(MAX_CARAC+1);
    if (line_indent == NULL)
        return 4;
    line_indent[0] = '\0';
    
    char indentation[3] = {"  "};
    // Pas besoin de déclarer k, incr et spacesbegin à l'extérieur du while
    // puisque tu les initialises dans le premier while
    // (c'est pas grave sinon tkt)
    int k = 0;
    int incr = 0; // Rapprocher cette ligne de ce à quoi elle se rapporte "logiquement"
    int spacesbegin = 0;

    //while (fgets(line, 1000, in) != NULL) 
    // Attention ici fgets lit 1000-1 caractères au maximum. 
    // Donc, on lit 999 caractères au maximum. 
    // (On perd donc un '\n' par exemple si la ligne faisait 1000 caractères avec le '\n')
    while (fgets(line, MAX_CARAC+1, in) != NULL) 
    {
        char *linetmp = line;
        k = 0;
        line_indent[0] = '\0';
        spacesbegin = 0;
        int j = 0;
        while (line[j] != '\n' && isspace(line[j]))
        {
            spacesbegin++;
            j++;
        }
        while ((linetmp = strstr(linetmp, "\\end")))
        {
            if (strstr(linetmp, "\\end") != NULL && line[spacesbegin] == '\\' && line[spacesbegin + 1] == 'e')
            {
                incr -= 1;
                k = 1;
                break;
            }
            linetmp++;
        }
        linetmp = line;
        for (int i = 0; i < incr; i++)
        {
            strcat(line_indent, indentation);
        }
        strcat(line_indent, &linetmp[spacesbegin]);
        fprintf(out, "%s", line_indent);
        while ((linetmp = strstr(linetmp, "\\end")))
        {
            incr -= 1;
            linetmp++;
        }
        linetmp = line;
        while ((linetmp = strstr(linetmp, "\\begin")))
        {
            incr += 1;
            linetmp++;
        }
        linetmp = line;
        if (k == 1)
            incr += 1;
    }
    fclose(in);
    fclose(out); 
    // Si out = stdout, faire un fclose dessus est bizarre dans
    // le sens où ce close est fait auto par la sortie du programme. 
    //Ça n'en reste pas moins tout à fait juste.
    free(line);
    free(line_indent);
    return 0;
}

void display_usage(char *argv[])
{
    printf("Usage: %s fichier_latex [fichier_indenté]", argv[0]);
    printf("Si 'fichier_indenté' est omis,\nl'affichage se fait sur la sortie standard.");
    return;
}