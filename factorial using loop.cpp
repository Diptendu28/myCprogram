#include<stdio.h>
int main()
{
	int i=1,fact=1,sum=0,n;
	printf("enter a number");
	scanf("%d",&n);
	for(;i<=n;i++)
	{
		fact=fact*i;
		sum=sum+fact;
	}
	printf("%d",sum);
	return 0;
}

	



	

