/*pattern 6(rhambaus)*/
#include<stdio.h>
int main()
{
	int i,j,n;
	printf("enter no of rows");
	scanf("%d",&n);
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=7;j++)
		{
			if(j>=5-i&&j<=8-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
