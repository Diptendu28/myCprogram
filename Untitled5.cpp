#include<stdio.h>
#include<math.h>
int main()
{
	int i=1,n,k,d,c;
	printf("enter the number");
	scanf("%d",&n);
	for(k=n;k>0;k=k/10)
	{
		c=pow(10,i);
		d=n%c;
		if(d==0)
		i=i+1;
		else
		{
			d=n/pow(10,i-1);
			printf("%d",d);
			break;
		}
	}
}

