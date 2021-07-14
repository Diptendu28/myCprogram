
/*13579
  35791
  57913
  79135
  91357*/
#include <stdio.h>

int main()
{
    int i,j,k;
    for(i=1;i<=9;i=i+2)
    {
        for(j=i;j<=9;j=j+2)
        {
            printf("%d",j);
            
        }
        if(i>1)
        for(k=1;k<=i-2;k=k+2)
        {
            printf("%d",k);
        }
        printf("\n");
    }
}   
    
