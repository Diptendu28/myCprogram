/*CIRCULAR PRIME NO*/
#include<stdio.h>
#include<math.h>
int n;
int digit(int n);
int prime(int a);
int circle(int a);
int prime(int a)
{
	int l=0,f=1;
	for(l=2;l<a;l++)
	{
		if(a%l==0)
		f=0;
	}
	return f;
}
int circle(int a)
{
	int x=0,y=0,n=0;
	x=a/10;
	y=a%10;
	n=y*pow(10,digit(a)-1)+x;
	printf("%d ",n);
	return n;	
}
int digit(int n)
{
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	return i;
}
int main()
{
	int d=0,p=1;
	printf("enter no");
	scanf("%d",&n);
	d=digit(n);
	for(int i=1;i<d;i++)
	{
		if(prime(n)==0)
		{
			p=0;
			break;
		}
		n=circle(n);
	}
	if(p==1)
	printf("\n circular prime");
	else
	printf("\n not circular prime");
	return 0;
}
