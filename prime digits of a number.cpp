/* prime digits*/
#include<stdio.h>
int main()
{
	int num=0,digit=0,prime;
	printf("enter a number");
	scanf("%d",&num);
	while(num>0)
	{
		digit=num%10;
		num=num/10;
		if(digit==1 || digit==2 || digit==3 || digit==5 || digit==7)
			printf("\n %d is prime",digit);
	}
	return 0;
}
