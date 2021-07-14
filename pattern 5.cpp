/*  ****1
    ***2
    **3
    *4
    5  */
#include<stdio.h>
int main()
{
	int i,j,p=1,n;
	printf("enter no of rows");
	scanf("%d",&n);
	for(i=4;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("%d\n",p);
		p=p+1;
	}
    printf("%d",p); 
}
