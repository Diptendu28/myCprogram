/* 13      14      15      16
   9       10      11      12
   5       6       7       8
   1       2       3       4  */

#include<stdio.h>
int main()
{
	int i,j,s,n;
	printf("enter no of rows");
	scanf("%d",&n);
	s=n*n-n+1;
	for(i=1;i<=n;i++)
	{
		
		for(j=s;j<=s+n-1;j++)
		{
			printf("%d \t",j);
		}
		printf("\n");
		s=s-n;
	}
}
