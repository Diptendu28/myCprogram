/*3
  4 5
  6 7 8
  9 10 11 12 */

#include<stdio.h>
int main()
{
	int i,j,k=3,n,p;
	printf("enter no of rows");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=k;
		for(j=1;j<=i;j++)
		{
			printf("%d ",p++);
		}
		printf("\n");
		k=k+i;
	}
}
