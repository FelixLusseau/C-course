
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __allow_allow = -1;



#define calloc(a,b) (__allow_allow-- ? calloc(a,b) : 0)
#define malloc(a) (__allow_allow-- ? malloc(a) : 0)
#define realloc(a,b) (__allow_allow-- ? realloc(a,b) : 0)

#include "student.h"

int main(void) {
    scanf("%i", &__allow_allow);
    fgetc(stdin); // \n

    Student * s = student_create();
    if(s == NULL) {
        printf("Etudiant non créé\n");
        return 0;
    }
    student_print(s);
    student_free(s);

    // test avec NULL ne doit pas buguer!!
    student_free(NULL);
}