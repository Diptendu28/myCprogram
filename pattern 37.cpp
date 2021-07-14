/* 1
  2 2
 3   3
4     4
 3   3
  2 2
   1  */
#include<stdio.h>
int main()
{
	int i,j,k,l;
	for(i=1;i<=4;i++)
	{
		for(k=4-i;k>=1;k--)
		{
			printf(" ");
		}
		printf("%d",i);
		if(i>1)
		{
			for(l=1;l<=2*i-3;l++)
			{
				printf(" ");
			}
			printf("%d",i);
		}
		printf("\n");
	}
	for(i=3;i>=1;i--)
	{
		for(k=3;k>=i;k--)
		{
			printf(" ");
		}
		printf("%d",i);
		if(i>1)
	{
		for(l=1;l<=2*i-3;l++)
		{
			printf(" ");
		}
		printf("%d",i);
	}
	printf("\n");
}
}
