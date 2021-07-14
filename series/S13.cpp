/* BCA1,BCB2,BCC3,BCD4,...*/
#include<stdio.h>
int main()
{
	char ch='a';
	int n,i;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("BC%c%d, ",ch,i);
		ch=ch+1;
	}
}
