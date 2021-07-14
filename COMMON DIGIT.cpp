/* COMMON DIGIT */
#include<stdio.h>
int main()
{
	int i,n,s,c1,c2,d,x,y;
	printf("enter a number");
	scanf("%d",&n);
	printf("enter another number");
	scanf("%d",&s);
	for(i=0;i<=9;i++)
	{
		c1=0;
		c2=0;
		x=n;
		y=s;
		while(x>0)
		{
			d=x%10;
			x=x/10;
			if(d==i)
			c1++;
		}
		while(y>0)
		{
			d=y%10;
			y=y/10;
			if(d==i)
			c2++;
		}
		if(c1>0&&c2>0)
		printf("common digit=%d\n",i);
	}
}
