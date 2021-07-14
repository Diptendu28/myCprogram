/* highest number*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,big=0;
	printf("\n enter 1st number");
	scanf("%d",&a);
	printf("\n enter 2nd number");
	scanf("%d",&b);
	printf("\n enter 3rd number");
	scanf("%d",&c);
	printf("\n enter 4th number");
	scanf("%d",&d);
	big=a;
	if(b>big)
	{
		big=b;
	}
	if(c>big)
	{
		big=c;
	}
	if(d>big)
	{
		big=d;
	}
	printf("\n biggest number is %d",big);
	return 0;
}
