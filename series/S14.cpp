/*A1,B2,C3,......,Y25,Z26,A1,B2...*/
#include<stdio.h>
int main()
{
	char ch='A';
	int n,i;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%c%d, ",ch,i);
		if(ch=='Z')
		{
			ch='A';
			i=0;
			n=n-26;
		}
		else
		ch=ch+1;
	}
}
