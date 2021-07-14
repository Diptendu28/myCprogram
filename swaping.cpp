/* swaping two numbers*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	printf("\n enter a number");
	scanf("%d",&a);
	printf("\n enter another number");
	scanf("%d",&b);
	c=a;
	a=b;
	b=c;
	printf("\n first number =%d",a);
	printf("\n second number =%d",b);
	return 0;
}
