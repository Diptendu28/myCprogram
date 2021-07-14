/*bigger number*/
#include<stdio.h>
int main()
{
	int a=0,b=0;
	printf("\n enter one number");
	scanf("%d",&a);
	printf("\n enter another number");
	scanf("%d",&b);
	if(a>b)
	{
		printf("\n %d is higher");
	}
	if(b>a)
	{
		printf("\n %d is higher");
	}
	if(a==b)
	{
		printf("\n equal no");
	}
	return 0;
}
