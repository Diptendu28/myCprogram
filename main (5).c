/*1234
  2341
  3412
  4123*/
#include <stdio.h>

int main()
{
    int i,j,k;
    for(i=1;i<=4;i++)
    {
        for(j=i;j<=4;j++)
        {
            printf("%d",j);
            
                
        }
        if(i>1)
        for(k=1;k<=i-1;k++)
        {
            printf("%d",k);
        }
        printf("\n");
    }
}   
    
