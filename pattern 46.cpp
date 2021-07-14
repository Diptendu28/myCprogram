/*   1
	 1 2
     2 3 4
     3 4 5 6
     4 5 6 7 8  */

#include<stdio.h>
int main()
{
	int n,i,j,c;
	printf("enter the number of turns");
	scanf("%d",&n);
	printf("1\n");
	for(i=1;i<n;i++)
	{
		c=i;
		for(j=0;j<=i;j++)
		{
			printf("%d ",c++);
		}
		printf("\n");
	}
	return 0;
}
