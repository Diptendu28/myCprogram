/*HEAP SORT*/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}
void heapify(int *arr,int n,int i)
{
    int largest=i,l=0,r;
    l=2*i+1;
    r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int *arr,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void display(int *arr,int n)
{
	int i;
	printf("Sorted array in ascending order:\n");
  	for(i=0;i<n;i++)
      printf("%d\t",arr[i]);
    printf("\n");
}
int main()
{
    int *arr,n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
	printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heapsort(arr,n);
    display(arr,n);
    free(arr);
	return 0;
}
