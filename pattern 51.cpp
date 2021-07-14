/* 	1
	2 4
	3 5 7
	6 8 10 12
	9 11 13 15 17
	14 16 18 20 22 24  */
#include<stdio.h>
int main()
{
	int i=1,j=2,n,a,count;
	printf("enter no of rows:");
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	{
		for(count=1;count<=a;count++)
		{
			if(a%2==0)
			{
				printf("%d ",j);
				j=j+2;
			}
			else
			{
				printf("%d ",i);
				i=i+2;
			}
		}
		printf("\n");
	}
	return 0;
}
