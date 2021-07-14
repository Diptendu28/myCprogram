/* A1,B2,C4,D8....*/
#include<stdio.h>
int main()
{
	char ch='a';
	int n,i,p=1;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%c%d, ",ch,p);
		p=p*2;
		ch=ch+1;
	}
}
