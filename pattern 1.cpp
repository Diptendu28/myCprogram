/*  ****
    ***
    **
    *   */

#include<stdio.h>
int main()
{

	int i,j,N;
	printf("enter no of rows:");
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		for(j=4;j>=i;j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
