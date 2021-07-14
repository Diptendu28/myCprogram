/*s=9+99+8+89+7+79*/
#include<stdio.h>
int main()
{
	int a=9,b=99,c,s=0,i=1,n;
	scanf("%d",&n);  
	while(i<=n)
	{
		c=a+b;
		s=s+c;
		a=a-1;
		b=b-10;
		i++;
	}
	printf("%d",s);
}
