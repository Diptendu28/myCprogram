/* INPUT 2 ARRAYS OF SIZE 10 EACH .COPY THEM IN AN THIRD ARRAY ONE AFTER OTHER.PRINT THE THIRD ARRAY */
#include<stdio.h>
int main()
{
	  int i,j=0,a[10],b[10],c[20],n=0;
	  printf("enter elements of 1st array");
	  for(i=0;i<10;i++)
	  {
	  	scanf("%d",&a[i]);
	  }
	  printf("enter elements of 2nd array");
	  for(i=0;i<10;i++)
	  {
	  	scanf("%d",&b[i ]);
	  }
		for(i=0;i<20;i++)
	{
		if(i%2==0)
	  	{
	  		c[i]=a[j];
	  		j++;
		}
	  	else
	  	{  
		  	c[i]=b[n];
	  		n++;
		}
	}
	for(i=0;i<20;i++)
	printf(" %d ",c[i]);
}

