/*1,2,4,7,11*/
#include<stdio.h>
int main()
{
	int s=1,i,n;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%d,",s);
		s=s+i;
	}
}
