/* checking of three sides of a traingle*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	printf("\n enter 1st side");
	scanf("%d",&a);
	printf("\n enter 2nd side");
	scanf("%d",&b);
	printf(" \n enter 3rd side");
	scanf("%d",&c);
	if(a==b&& b==c)
	{
		printf("\n  traingle is equilateral ");
	}
	if(a==b&&b!=c||b==c&&c!=a||c==a&&a!=b)
	{
		printf(" \n traingle is isosceles");
	}
	if(a!=b&&b!=c&&c!=a)
	{
		printf("\n traingle is scalen");
	}
}
