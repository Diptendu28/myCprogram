/* S=1+1+2+3+5+8+13+21+.... n terms */
#include<stdio.h>
int main()
{
    int n,i,a=1,b=0,c,s;
    printf("enter a number");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        s=s+c;
    }
    printf("sum of the series is %d",s);
}
