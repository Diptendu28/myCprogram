/*x-1/2 + 1/2(x-1/2)^2 + 1/2(x-1/2)^3 +............*/
#include<stdio.h>
#include<math.h>
int main()
{
    int i,count=0;
    float sum=0.0,t=1,x=5;
    for(i=1;i<=3;i++)
    {
        if(count==0)
        {
            sum+=(x-1)/2;
            count++;
        }
        else
        {
            sum+=0.5*pow((x-1)/2,i);
        }
    }
    printf("%f",sum);
}