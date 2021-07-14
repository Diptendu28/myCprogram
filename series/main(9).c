/*sin(x)=x-x^3/3!+x^5/5!-x^7/7!+.........*/
#include<stdio.h>
int main()
{
    int n,i;
    float x,t,sum;
    printf("enter a number");
    scanf("%d",&n);
    printf("enter a no");
    scanf("%f",&x);
    x=x*(3.145/180);
    t=x;
    sum=x;
    for(i=1;i<=n;i++)
    {
        t=(t*(-1)*x*x)/(2*i*(2*i+1));
        sum+=t;
    }
    printf("sinx=%.4f",sum);
}
