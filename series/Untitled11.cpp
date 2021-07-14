/* 1+(1+2)+(1+2+3)+(1+2+3+4)+...........n terms*/
#include<stdio.h>
int main()
{
	int p=1,i=1,t=0,s=0,n;
	printf("enter a number:");
	scanf("%d",&n);
	while(i<=n)
	{
		t=t+p;
		s=s+t;
		p++;
		i++;
	}
	printf("sum of the series is %d",s);
	return 0;
}
