/*DIGIT COUNT IN A NUMBER*/
#include<stdio.h>
int n;
void digit();
void digit()
{
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	printf("number of the digit is %d",i);
}
int main()
{
	printf("enter a no");
	scanf("%d",&n);
	digit();
	return 0;
}

