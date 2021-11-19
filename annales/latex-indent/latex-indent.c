# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(int argc, char ** argv){
    if (argc<2){
        return 1;
    }
    FILE * in = fopen(argv[1], "r");
    if (in==NULL)
        return 2;
    FILE * out=NULL;
    if (argv[2]==NULL)
        out = stderr;
    else
        out = fopen(argv[2], "w");
    if (out==NULL)
        return 3;
    char * line = malloc(1000);
    if (line==NULL)
        return 4;
    int incr=0;
    char * line_indent=malloc(1000);
    if (line_indent==NULL)
        return 4;
    line_indent[0]='\0';
    char indentation[3]={"  "};
    int spacesbegin = 0;
    int k=0;
    while(fgets(line, 1000, in)!=NULL){
        k=0;
        line_indent[0]='\0';
        spacesbegin=0;
        int j=0;
        while (line[j]!='\n' && isspace(line[j])){
                spacesbegin++;
                j++;
        }
        if (strstr(line, "\\end")!=NULL && strstr(line, "\\begin")==NULL && line[spacesbegin]=='\\' && line[spacesbegin+1]=='e'){
            incr-=1;
            k=1;
        }
        for (int i=0; i<incr; i++){
            strcat(line_indent, indentation);
        }
        strcat(line_indent, &line[spacesbegin]);
        //printf("%s", line_indent);
        fprintf(out, "%s", line_indent);
        if (strstr(line, "\\end")!=NULL && strstr(line, "\\begin")==NULL && k==0){
            incr-=1;
        }
        if (strstr(line, "\\begin")!=NULL && strstr(line, "\\end")==NULL){
            incr+=1;
        }
    }
    fclose(in);
    fclose(out);
    free(line);
    free(line_indent);
    return 0;
}