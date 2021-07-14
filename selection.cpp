/*selection sort*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *b,int *c)
{
	int temp;
	temp=*b;
	*b=*c;
	*c=temp;
}
void selectionsort(int *a,int n)
{
	int i,j,min_index;
	for(i=0;i<n-1;i++)
  {
    min_index=i;
	for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min_index])
		min_index=j;
    }
    if(i!=min_index)
    	swap(&a[i],&a[min_index]);
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
  selectionsort(a,n);
  display(a,n);
  return 0;
}
