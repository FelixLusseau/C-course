#include <string.h>

void copy(char *ch1, char **ch2){
   *ch2=malloc(strlen(ch1)+1);
    if (*ch2==NULL)
        return;
    else
    {
        for (int i=0; i<(int)strlen(ch1)+1; i++)
        {
            (*ch2)[i]=ch1[i];
        }
    }

}