/* 1 + 1+2/1*2 + 1+2+3/1*2*3 +.........n terms */
#include<stdio.h>
int main()
{
	int i=1,num=0,no,den=1;
	float sum=0.0,term;
	printf(" enter value of no");
	scanf("%d",&no);
	for(;i<=no;i++)
	{
		num+=i;
		den*=i;
		term=(float)num/(float)den;
		sum+=term;
	}
	printf("%f",sum);
	return 0;
}
