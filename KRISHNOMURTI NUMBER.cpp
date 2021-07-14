/* KRISHNOMURTI NUMBER */
#include<stdio.h>
int main()
{
	int sum=0,fact,n,r,t,i;
	printf("enter a number");
	scanf("%d",&n);
	t=n;
	while(n!=0)
	{
		fact=1;
		r=n%10;
		for(i=1;i<=r;i++)
		{
			fact=fact*i;
		}
		sum=sum+fact;
		n=n/10;
	}
	if(sum==t)
	printf("number is krishnomurti");
	else
	printf("number is not");
}
