#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * removeLetter(char * chaineinit, char carac)
{
    char * chaine = malloc(strlen(chaineinit)+1);
    if (chaine==NULL)
        return NULL;
    strcpy(chaine,chaineinit);
    for (int i=0; chaine[i]!='\0'; i++)
    {
        if (chaine[i] == carac)
        {
            for (int k=i; chaine[k]!='\0'; k++)
            {
                chaine[k]=chaine[k+1];
            }
            i--;
        } 
    }
    return chaine;
}