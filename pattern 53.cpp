/*Pattern 52(another algo)*/
#include<stdio.h>
int main()
{
	int i,k,n;
	printf("enter no of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(k=n-1;k>=i;k--)
			printf(" ");
		printf("*");
		for(k=1;k<=2*(i-1)-1;k++)
			printf(" ");
		if(i!=1)
			printf("*");
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=2*n-1+i-1;k++)
			printf(" ");
		printf("*");
		for(k=2*(n-i)-1;k>=1;k--)
			printf(" ");
		if(i!=n)
			printf("*");
		printf("\n");
	}
}
