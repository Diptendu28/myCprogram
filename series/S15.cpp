/*14,28,20,40,32,64,....*/
#include<stdio.h>
int main()
{
	int n,i,p=14;
	printf("enter no");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			printf("%d,",(p*2));
			p=p+6*(i/2);
		}
		else
		printf("%d,",p);
	}
}
