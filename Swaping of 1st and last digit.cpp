/*Swaping of 1st and last digit*/
#include<stdio.h>
int main()
{
	int n,fd,ld,c,d,rev=0,temp,swap;
	printf("enter a no");
	scanf("%d",&n);
	temp=n;
	ld=n%10;
	while(n>10)
	{
		n=n/10;
	}
	fd=n;
	n=temp/10;
	while(n>10)
	{
		c=n%10;
		rev=rev*10+c;
		n=n/10;
	}
	swap=ld;
	while(rev>0)
	{
		d=rev%10;
		swap=swap*10+d;
		rev=rev/10;
	}
	swap=swap*10+fd;
	printf("swap =%d",swap);
	return 0;
}
