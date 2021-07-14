/*s=1/2+2/3*/
#include<stdio.h>
int main()
{
	int  ctr,den,num,n;
	float sum=1.0,t;
	printf("enter a number");
	scanf("%d",&n);
	for(ctr=1;ctr<=n;ctr++)
	{
		num=ctr;
		den=ctr+1;
		t=(float)num/(float)den;
		sum=sum+t;
	}
	printf("%f",sum);
	return 0;
}
