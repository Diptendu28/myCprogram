/* MULTIPLE HARSHAD NUMBER*/
#include<stdio.h>
int digitsum(int);
int harshad(int);
int digitsum(int n)
{
	int temp=n,sum=0,rem=0;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum+rem;
		temp=temp/10;
	}
	return sum;
}
int harshad(int n)
{
	int s=digitsum(n);
	if(n%s==0)
		return 1;
	else
		return 0;
}
int main()
{
	int n=0;
	printf("\nEnter a number:");
	scanf("%d",&n);
	if(harshad(n)==1)
	{
		printf("\n%d is a harshad number",n);
		if(harshad(n/digitsum(n))==1)
			printf("\n%d is a multiple harshad no",n);
	}	
	else
		printf("\nIt is not even a harshad no");
	return 0;
}
