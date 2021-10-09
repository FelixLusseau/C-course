#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);
    if (n==1)
        {
            printf("#");
        }
    for (int i=1; i<=n/2; i++)
    {
        if (n%2!=0 && n>1)
        {
          printf("#");
          for (int i=1; i<=n/2; i++)
          {
              
              printf(".#");
          }  
          printf("\n");
          printf(".");
          for (int i=1; i<=n/2; i++)
          {
              
              printf("#.");
          }  
          printf("\n");
        }
        if (n%2==0)
        {
          for (int i=1; i<=n/2; i++)
          {
              printf("#.");
          }  
          printf("\n");
          for (int i=1; i<=n/2; i++)
          {
              printf(".#");
          }  
          printf("\n");
        }  
    }
    if (n%2!=0 && n>1)
        {
          printf("#");
          for (int i=1; i<=n/2; i++)
          {
              printf(".#");
          }  
        }
    return 0;
}