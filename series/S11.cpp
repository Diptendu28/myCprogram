/* A1,B2,C3......*/
#include<stdio.h>
int main()
{
	char ch='a';
	int n,i;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%c%d, ",ch,i);
		ch=ch+1;
	}
}
