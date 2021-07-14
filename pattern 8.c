
/*10101
  01010
  10101
  01010
  10101*/
#include <stdio.h>
int main()
{
    int i,j,p=0,q=1,a;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(j%2==0)
            printf("%d",p);
            else
            printf("%d",q);
        }
        a=p;
        p=q;
        q=a;
        printf("\n");
    }
}






