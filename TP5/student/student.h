#include <stdio.h>

typedef struct {
    char * name;
    int birthYear;
    int id;
} Student;

Student * student_create(void){
    Student *s=malloc(sizeof(Student));
    if (s==NULL)
    {
        free(s);
        return NULL;
    }
    char * nom=malloc(1000*sizeof(char));
    if (nom==NULL){
        free(nom);
        free(s);
        return NULL;
    }
    
    fgets(nom, 1000, stdin);
    s->name=nom;
    scanf("%i", &s->birthYear);
    scanf("%i", &s->id);
    return s;
}

void student_print(Student * s){
    printf("id:        %i\n", s->id);
    printf("name:      %s", s->name);
    printf("birthYear: %i\n", s->birthYear);

}

void student_free(Student * s){
    if (s==NULL)
        return;
    free(s->name);
    free(s);
        
}