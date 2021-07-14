/*1,1,5,5,9,9,....*/
#include<stdio.h>
int main()
{
	int n,i,p=1;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			printf("%d,",p);
			p=p+4;
		}
		else
		printf("%d,",p);
	}
}
