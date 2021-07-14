/* Automorphic no*/
#include<stdio.h>
#include<math.h>
void automorphic(int n);
void automorphic(int n)
{
	int sq,d=0,p,rem,num=n;
	sq=n*n;
	while(num!=0)
	{
		d++;
		num=num/10;
	}
	p=pow(10,d);
	rem=sq%p;
	if(rem==n)
	printf("yes");
	else
	printf("no");
}
int main()
{
	int n;
	printf("enter a no");
	scanf("%d",&n);
	automorphic(n);
	return 0;
}
