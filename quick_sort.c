/*quick sort*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *b,int *c)
{
	int temp;
	temp=*b;
	*b=*c;
	*c=temp;
}
void quicksort(int *a,int low,int high)
{
	int p;
	if(low<high)
	{
		p=partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}
int partition(int *a,int low,int high)
{
	int pivot,i,j;
	pivot=a[high];
	i=low-1;
	for(j=low;j<=high-1;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
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
  int *a,n,i;
//  low=0;
//  high=n-1;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  printf("Enter %d integers\n",n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  quicksort(a,0,n-1);
  display(a,n);
  return 0;
}
