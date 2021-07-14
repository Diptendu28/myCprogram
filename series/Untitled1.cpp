/*1,2,2,4,8,32,.......*/
#include<stdio.h>
int main()
{
    int n,i,a=1,b=2,c;
    printf("\nEnter the number of turns:");
    scanf("%d",&n);
    if(n==1)
        printf("%d",a);
    if(n==2||n>2)
    {
        printf("%d %d",a,b);
        for(i=2;i<n;i++)
        {
            c=a*b;
            printf(",%d",c);
            a=b;
            b=c;
        }
    }
    return 0;
}
