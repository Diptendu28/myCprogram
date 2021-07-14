/* FIBO PRIME */
#include<stdio.h>
int main()
{
	int n=1,i,a=1,b=0,c,j;
	printf("\n enter a no");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		int prime=1;
		for(j=2;j<=c-1;j++)
		{
			if(c%j==0)
			{
				prime=0;
			}
		}
		if(prime==1)
		{
			printf("\n %d is fibo prime",c);
		}
	}
}
