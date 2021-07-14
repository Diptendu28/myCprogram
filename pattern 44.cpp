/* 10 9 8 7
   6 5 4
   3 2
   1 */
#include<stdio.h>
int main()
{
	int i,j,s=10;
	for(i=4;i>=1;i--)
	{
		for(j=i;j>=1;j--)
		{
			printf("%d ",s--);
		}
		printf("\n");
	}
}
