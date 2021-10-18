#include <stdio.h>
#include <math.h>

void norm_vect(vector_2D * vect){
    double x = vect->x;
    double y = vect->y;
    double norme = sqrt(x*x+y*y);
    if (norme==0)
        return;
    vect->x = vect->x/norme;
    vect->y = vect->y/norme;
}

void norm_vect_xy(double * x, double * y){
    double norme = sqrt(*x**x+*y**y);
    if (norme==0)
        return;
    *x=*x/norme;
    *y=*y/norme;
}