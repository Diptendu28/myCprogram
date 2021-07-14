/* 2-4+6-8*/
#include<stdio.h>
#include<math.h>
int main()
{
	int i=0,n,s=0,p;
	printf(" enter a number\n");
	scanf("%d",&n);
	while(i<=n)
	{
		p=pow(-1,i+1);
		s+=p*2*i;
		i++;
	}
	printf("%d",s);
}
