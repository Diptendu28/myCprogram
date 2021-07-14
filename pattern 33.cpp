/*  1
   121
  12321
 1234321
123454321 */
#include<stdio.h>
int main()
{
	int i,j,k,s;
	for(i=1;i<=5;i++)
	{
		for(s=1;s<=5-i;s++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			
			printf("%d",j);
		}
		for(k=i-1;k>=1;k--)
		{
			printf("%d",k);
		}
		printf("\n");
	}
}
