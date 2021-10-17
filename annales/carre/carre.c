#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    long long unsigned int N;
    scanf("%llu", &N);
    float k=sqrt(N);
    long long unsigned int kk=(long long unsigned int)k;
    if (N<=0 && N>=1000000000000000000)
        return 1;    
    else if (N==0)
        {
        printf("1");
        return 0;
        }
    else if (N==1)
        printf("PARFAIT\n");    
    /*printf("%lli\n", kk);
    printf("%Lf\n\n", k);*/
    else if (kk==k)
    {
        long long unsigned int nbSuivant = 0;
        long long unsigned int i=0;
        while (nbSuivant<=N)
        {
            i++;
            nbSuivant=i*i+1;
        }
    printf("%llu\n", nbSuivant);
    }
    else
        printf("PARFAIT\n");
    return 0;
}