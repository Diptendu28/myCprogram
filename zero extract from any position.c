/*extract zero from any position of a number */
#include<stdio.h>
int main()
{
    int k,n,s=0,d,r=0;
    printf("enter a n  o");
    scanf("%d",&n);
    for(k=n;k>0;k=k/10)
    {
        d=k%10;
        if(d==0)
        continue;
        else
        s=s*10+d;
    }
    for(k=s;k>0;k=k/10)
    r=r*10+k%10;
    printf("%d",r);
}