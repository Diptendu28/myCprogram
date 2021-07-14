/*  1
   131
  13531
 1357531
135797531 */    
#include<stdio.h>
int main()
{
	int i,j,k,s;
	for(i=1;i<=9;i=i+2)
	{
		for(s=1;s<=9-i;s=s+2)
		{
			printf(" ");
		}
		for(j=1;j<=i;j=j+2)
		{
			printf("%d",j);
		}
		for(k=i-2;k>=1;k=k-2)
		{
			printf("%d",k);
		}
		printf("\n");
	}
}
