/* 123454321
   1234 4321
   123   321
   12     21
   1       1 */
#include<stdio.h>
int main()
{
	int i,j,k,p=1,s;
	for(i=5;i>=1;i--)
	{ 
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		for(k=1;k<=2*p-3;k++)
		{
			printf(" ");
		}
		for(s=i;s>=1;s--)
		{
			if(s<5)
			printf("%d",s);
		}
		printf("\n");
		p++;
	}
}

