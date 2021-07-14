/*(1*2)+(2*3)+....n terms*/
#include<stdio.h>
int main()
{
int i=1,a=1,b=2,c,s=0,n;
scanf("%d",&n);
while(i<=n)
{
	c=a*b;
	s=s+c;
	a=a+1;
	b=b+1;
	i++;

}
printf("sum of the series =%d",s);
}


	
