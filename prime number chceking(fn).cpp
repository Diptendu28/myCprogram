/* checking of prime number using function*/
#include<stdio.h>
int n;
void prime()
{
	int i,f=0;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	printf("%d is prime",n);
	else
	printf("%d is not prime",n);
}
void input()
{
	scanf("%d",&n);
}
int main()
{
	printf("enter the  number");
	input();
	prime();
	return 0;
}
	


