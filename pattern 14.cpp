/* 12345
   22345
   32345
   43245
   54325  */
#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=5;i++)
	{
		if(i>=2)
		for(j=i;j>=2;j--)
		{
			printf("%d",j);
		}
		for(k=i;k<=5;k++)
		{
			printf("%d",k);
		}
		printf("\n");
	}
	
}
