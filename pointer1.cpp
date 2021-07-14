/*SWAP USING POINTER*/
#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int x=10,y=15;
	printf("%d %d\n",x,y);
	swap(&x,&y);
	printf("%d %d\n",x,y);
}
