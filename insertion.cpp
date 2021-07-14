/*insertion sort*/
#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *a,int n)
{
	int i,j,key;
	for(i=0;i<n;i++)
  	{
    	key=a[i];
    	j=i-1;
		while(j>=0&&a[j]>key)
    	{
      		a[j+1]=a[j];
			j=j-1;
    	}
		a[j+1]=key;
	}
}
void display(int *a,int n)
{
	int i;
	printf("Sorted list in ascending order:\n");
  	for(i=0;i<n;i++)
      printf("%d\n",a[i]);
}
int main()
{
  int *a,n,i,j,flag;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  printf("Enter %d integers\n",n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insertionsort(a,n);
  display(a,n);
  return 0;
}
