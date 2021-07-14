/* *********
   **** ****
   ***   ***
   **     **
   *       *  */
#include<stdio.h>
int main()
{
	int i,j,k,s,p=1;
	for(i=5;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		for(k=1;k<=2*p-3;k++)
		{
			printf(" ");
		}
		for(s=i;s>=1;s--)
		{
			if(s<5)
			printf("*");
		}
		printf("\n");
		p++;
	}
}
