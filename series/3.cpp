/* s=2-4+6-8 */
#include<stdio.h>
int main()
{
	int i,s=0,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		s=s-(2*i);
	else
	
		s=s+(2*i);
	}
	printf("%d",s);
	return 0;
}
