/* s=1+1+2+3+5+8+13+21+.....n terms */
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,a=1,b=0,c,s;
	printf(" how many terms do you want in fibonaci series?");
	scanf("%d",&n);
	s=a+b;
	while(i<n)
	{
		c=a+b;
		printf("%d",c);
		a=b;
		b=c;
		s=s+c;
		i++;		
	}
	printf(" sum of fibonaci series is %d",s);
}
