/* input 10 numbers and print the biggest */
#include<stdio.h>
int main()
{
	int i,b,big,n;
	printf("enter a number");
	scanf("%d",&big);
	for(i=1;i<=10;i++)
	{
		printf("enter a number");
		scanf("%d",&n);
		if(big<n)
		big=n;
	}
	printf("biggest no=%d",big);
}
