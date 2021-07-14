/* input a matrix . print bii=ggest/smallest of each row */
#include<stdio.h>
int main()
{
	int a[4][4],i,j,s=0,b=0,s1,b1;
	printf("enter the elements of the array");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<4;i++)
	{
		s=a[i][j];
		b=0;
		s1=a[i][j];
		b1=0;
		for(j=0;j<4;j++)
		{
			if(s>a[i][j])
			s=a[i][j];
			if(s1>a[j][i])
			s1=a[j][i];
			if(b<a[i][j])
			b=a[i][j];
			if(b1<a[j][i])
			b1=a[j][i];
		}
		printf("the smallest number in %d row is %d\n",i,s);
		printf("the biggest number in %d row is %d\n",i,b);
		printf("the smallest number in %d column is %d\n",i,s1);
		printf("the biggest number in %d column is %d\n",i,b1);
	}
}
