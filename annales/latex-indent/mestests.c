# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

/* int main(void){ 
  char * line = "\\begin{center1} text \\begin{center2} text \\begin{center3}";
  while ((line=strstr(line, "\\begin"))){
    printf("%s\n", line);
    line++;
  }
    return 0;
} */
 

int main(void){
  char * linetmp = "      \\begin{center1} text \\end{center1} \\end{center3}";
  printf("lintemp :%s\n", linetmp);
  int spacesbegin=0;
  int j=0;
  while (linetmp[j]!='\n' && isspace(linetmp[j])){
                spacesbegin++;
                j++;
        }
  printf("spacesbegin : %i\n", spacesbegin);
  while ((linetmp=strstr(linetmp, "\\end"))){
        printf("lintemp while :%s\n", linetmp);
        if (strstr(linetmp, "\\end")!=NULL && strstr(linetmp, "\\begin")==NULL){
            printf("ok\n");            
        }
        //printf("inc end2 : %i\n", incr);
        linetmp++;
        }
  return 0;
}