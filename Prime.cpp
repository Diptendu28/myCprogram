//testing of prime numbers//
#include<stdio.h>
int main()
{
	int n,i,prime=1;
	printf("enter the number ",n);
	scanf("%d",&n);
	
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
		{
			prime=0;
		}
	}
	if (prime==1)
	{
		printf("%d is prime",n);
	}
	else
	{
		printf("%d is not prime",n);
	}
	return 0;
}
