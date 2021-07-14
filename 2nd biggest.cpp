/* 2nd biggest */
#include<stdio.h>
int main()
{
	int i,n,big,sbig;
	printf("\n enter a no ");
	scanf("%d",&big);
	for(i=1;i<=9;i++)
	{
		printf("\nenter a no ");
		scanf("%d",&n);
		if(big<n)
		{
			sbig=big;
			big=n;
		}
		if(n<big&&n>sbig)
		{
			sbig=n;
		}
	}
	printf("second biggest no=%d",sbig);
}
