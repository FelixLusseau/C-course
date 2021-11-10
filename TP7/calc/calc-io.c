# include "calc-io.h"
# include <stdio.h>
# include <math.h>

void printResult(double a, double b, char op){
    double res;
    //printf("%f %f\n", a,b );
    if (op == '+')
        res = a+b;
    else if (op == '*')
        res = a*b;
    else if (op == '-')
        res = a-b;
    else if (op == '/')
        res = a/b;
    else if (op == '^')
        res = pow(a,b);
    printf("%f %c %f = %f\n", a, op, b, res);
}