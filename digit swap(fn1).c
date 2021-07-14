/* number swap*/
#include<stdio.h>
int extractM(int);
int count(int);
int extractL(int);
int extract1(int);
int nPower(int,int);
void main()
{
  	int num,n,i,j,k,p;
	printf("enter n:");
    scanf("%d",&n);
  	p=nPower(10,count(n)-1);
  	i=extractM(n);
  	j=extractL(n);
  	k=extract1(n);
  	num=j*p+i*10+k;
  	printf("\n%d",num);
}
int extractM(int n)
{
  	int res=0,pos=1,digit;
  	while(n>10)
  	{
	    digit=n%10;
	    res=res+digit*pos;
	    pos=pos*10;
	    n=n/10;
  	}
  	return res/10;
}
int count(int n)
{
  	int ctr=0;
  	while(n>0)
  	{
	  ctr++;
	  n=n/10;
  	}
  	return ctr;
}
int extractL(int i)
{
  	int digit;
	digit=i%10;
	return digit;
}
int nPower(int a,int b)
{
  	int i,res=1;
  	for(i=1;i<=b;i++)
  	{
    	res=res*a;
  	}
  	return res;
}
int extract1(int j)
{
  	int first;
  	first=j/nPower(10,(count(j)-1));
  	return first;
}
