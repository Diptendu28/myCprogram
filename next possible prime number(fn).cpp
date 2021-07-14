/*identify a prime number .If it isn't a prime number print the next possible prime number*/
#include<stdio.h>
int prime(int n);
int prime(int n)
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
	return f;
}
int main()
{
	int n,i,f;
	printf("enter the  number");
	scanf("%d",&n);
	while(n>0)
	{
		f=prime(n);
		if(f==0)
		{
			printf("%d is a prime number",n);
			break;
		}
		else
		n=n+1;
	}
}
	


