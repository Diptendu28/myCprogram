/* Input two range . prime all prime numbers between them*/
#include<stdio.h>
int n1,n2;
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
int main()
{
	int i,u;
	printf("enter lower range");
	scanf("%d",&n1);
	printf("enter upper range");
	scanf("%d",&n2);
	for(i=n1;i<n2;i++)
	if(prime(i)==1)
	printf("\n prime no-%d",i);
}
