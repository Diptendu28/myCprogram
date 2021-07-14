/*KARPEKAR NO*/
#include<stdio.h>
#include<math.h>
int digit(int n);
void abc(int a);
int digit(int n)
{
  int i=0;
  while(n>0)
  	{
	    n/=10;
	    i++;
  	}
  return i;
}
void abc(int a)
{
  int p,s,x,y,d;
  s=a*a;
  printf("%d",s);
  for(int i=1;i<=digit(s);i++)
  	{
	    d=pow(10,i);
	    x=s/d;
	    y=s%d;
	    printf("\ndiffernt combinations are %d and %d",x,y);
	    p=x+y;
	    printf("\n %d",p);
	    if(p==a&&x&&y!=0)
	    {
	       printf("\nkarpekar no is %d\n",p);
	       break;
	    }
  	}
}
int main()
{
	  int n;
	  printf("enter a number:");
	  scanf("%d",&n);
	  abc(n);
}
