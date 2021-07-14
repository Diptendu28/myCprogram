/*GCD of two numbers using recursive function*/
#include<stdio.h>
int gcd(int,int);
int main()
{
	int a,b,i;
	printf("Enter the numbers: ");
	scanf("%d %d",&a,&b);
	printf("GCD of two numbers = %d",gcd(a,b));
	return 0;
}
int gcd(int p,int q)
{
	int rem;
	rem=p%q;
	p=q;
	q=rem;
	if(q!=0)
		return gcd(p,q);
	else
		return p;
}
