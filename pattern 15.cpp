/* 1
   01
   101
   0101
   10101 */
#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=5;i++)
	{
		if(i%2==0)
		for(j=1;j<=i;j++)
		{
			if(j%2==0)
			printf("1");
			else
			printf("0");
		}
		else
		for(k=1;k<=i;k++)
		{
			if(k%2==0)
			printf("0");
			else
			printf("1");
		}
		printf("\n");
	}
}
		
	
