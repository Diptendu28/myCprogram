/* swap using function*/
#include<stdio.h>
#include<math.h>
int n;
void swap();
void swap()
{
	int fd,ld,c=0,temp,d;
	temp=n;
	while(temp>0)
	{
		c=c+1;
		temp=temp/10;
	}
	ld=n%10;
	fd=pow(10,c-1);
	fd=n/fd;
	n=n/10;
	d=pow(10,c-2);
	n=n%d;
	temp=ld*pow(10,c-1)+n*10+fd;
	printf("%d",temp);
}
int main()
{
	printf("enter a no");
	scanf("%d",&n);
	swap();
	return 0;
}
