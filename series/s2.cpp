/* s= 1 - 2^2 + 3 - 4^2+....n terms */
#include<stdio.h>
int main()
{
 	int i,s=0,n;
 	printf("enter a number");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
 		if(i%2==0)
		 s=s-i*i;
	
	else
		s=s+i;
	}
	printf("%d",s);
}
