/* age checking*/
#include<stdio.h>
int main()
{
	int a=0;
	printf(" enter the age\n");
	scanf("%d",&a);
	if(a<13)
	{
		printf(" person is minor\n ");
	}
	if(a>=13&&a<18)
	{
		printf(" person is tennager\n ");
	}
	if(a>=18)
	{
		printf(" person is adult\n ");
	}
	if(a>=60)
	{
		printf(" person is senior citizen\n ");
	}
}
