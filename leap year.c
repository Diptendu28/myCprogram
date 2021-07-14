/*LEAP YEAR*/
#include<stdio.h>
int main()
{
    int a;
    printf("enter a year");
    scanf("%d",&a);
    if(a%400==0)
    {
        printf("leap year");
    }
    else
    {
    	if(a%4==0)
    	{
    		if(a%100==0)
    			printf("not a leap year");
    		else
    			printf("leap year");
		}
	}
}
