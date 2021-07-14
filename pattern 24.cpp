/*  1  2  4  7  11
    3  5  8  12
    6  9  13
    10  14
    15 */

#include<stdio.h>
int main()
{
	int i,j,p=0,s;
	for(i=1;i<=5;i++)
	{
		p=p+i;
		s=p;
	for(j=i;j<=5;j++)
	{
		printf(" %d ",s);
		s=s+j;
	}
	printf("\n");
}
}
