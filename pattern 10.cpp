 /*     1
       212
      32123
	 4321234
	543212345 */   
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,k,l;
	printf("enter no of rows");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>i;j--)
		{
			printf(" ");
		}
		for(k=i;k>=1;k--)
		{
			printf("%d",k);
		}
		for(l=2;l<=i;l++)
		{
			printf("%d",l);
		}
		printf("\n");
	}
	
}

