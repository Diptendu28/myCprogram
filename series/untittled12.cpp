/* (1*2)+(2*3)+(3*4)+....(19*20)*/
#include<stdio.h>
int main()
{
	int n=1,i,sum=0;
	for(;n<20;n++)
	{
		i=n*(n+1);
		sum=sum+1;
	}
	printf("sum=%d",sum);
	return 0;
}
