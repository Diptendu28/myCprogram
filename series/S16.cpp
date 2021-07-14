/*21,9,21,11,21,13,21,.....*/
#include<stdio.h>
int main()
{
	int n,i,p=9;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			printf("%d,",p);
			p=p+2;
		}
		else
		printf("%d,",21);
	}
}
