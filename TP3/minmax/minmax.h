#include <stdio.h>

void minmax(int *arr, int length, int *min, int *max){
    int mi = arr[0];
    int ma = arr[0];
    
    for (int i=0; i<length; i++)
    {
        if (arr[i]<mi)
            mi=arr[i];
        else if (arr[i]>ma)
            ma=arr[i];
    }
    *min = mi;
    *max = ma;
}