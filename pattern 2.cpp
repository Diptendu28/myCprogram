/*  *
    **
    ***
    ****
    ***
    **
    *   */
#include<stdio.h>
int main()
{
	int i,j,n,columns;
	printf("enter a number of cloumns");
	scanf("%d",&n);
	columns=1;
	for(i=1;i<=n*2;i++)
	{
		for(j=1;j<=columns;j++)
		{
			printf("*");
		}
		if(i<n)
		{
			columns++;
		}
		else
		{
			columns--;
		}
		printf("\n");
	}
	return 0;    
}
		
	
	
			
	

