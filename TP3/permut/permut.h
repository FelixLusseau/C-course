void permut(int *a, int *b, int*c){
    int A=*a;
    int B=*b;
    int C=*c;
    *a=B;
    *b=C;
    *c=A;
}