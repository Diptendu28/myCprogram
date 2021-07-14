/* PRIME FACTORS*/
#include<stdio.h>
void prime(int);
void prime(int num)
{
	int i=2;
	printf("prime factors of %d are ",num);
	while(num!=1)
	{
		if(num%i==0)
		{
			printf("%d ",i);
			num=num/i;
		}
		else
		{
			i++;
			continue;	
		}	
	}	
}
int main()
{
	int num;
	printf("enter a number");
	scanf("%d",&num);
	prime(num);
	return 0;
}
