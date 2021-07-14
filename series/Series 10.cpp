//[1+1/2+1/4+......+1/n]
#include<stdio.h>
int main()
{
	int i,n;
	double y=1;
	printf("Enter the no.of. terms: ");
	scanf("%d",&n);
	for(i=2;i<2*n-1;i+=2)
	{
		y=y+(1.0/i);
	}
	printf("The sum of the series is: %f",y);
}
