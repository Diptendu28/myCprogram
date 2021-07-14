/* *       *
   **     **
   ***   ***
   **** ****
   *********  */
#include<stdio.h>
int main()
{
	int i,j,k,s;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		for(k=1;k<=9-2*i;k++)
		{
			printf(" ");
		}
		for(s=1;s<=i;s++)
		{
			if(s<5)
			printf("*");
		}
		printf("\n");
	}
}
