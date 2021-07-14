/*1+1/2+1/4+1/8+......*/
#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,j;
    float s=0;
    printf("\nEnter number of turns:");
    scanf("%d",&n);
    printf("1");
    for(i=1;i<n;i++)
    {
        j=pow(2,i);
        printf("+1/%d",j);
        s=s+(1/pow(2,i));
        
    }
    printf("\n%.2f",s);
    return 0;
}

