#include <string.h>

void removeLetter(char * chaine, char carac)
{
    for (int i=0; chaine[i]!='\0'; i++)
    {
        if (chaine[i] == carac)
        {
            for (int k=i; chaine[k]!='\0'; k++)
            chaine[k]=chaine[k+1];
            i--;
        }
       
    }
}