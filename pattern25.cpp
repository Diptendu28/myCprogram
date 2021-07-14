/* A
   ABA
   ABCBA
   ABCDCBA
   ABCDEDCBA */
#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c",(j+65-1));
		}
		for(k=i-1;k>=1;k--)
		{
			printf("%c",(k+65-1));
		}
		printf("\n");
	}
}
