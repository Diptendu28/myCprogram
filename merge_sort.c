/*Merge sort*/
#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int beg,int mid,int end)
{
	int i,j,k;
	int n1=mid-beg+1;
	int n2=end-mid;
	int l[n1],o[n2];
	for(i=0;i<n1;i++)
		l[i]=arr[beg+i];
	for(j=0;j<n2;j++)
		o[j]=arr[mid+1+j];
	i=0;
	j=0;
	k=beg;
	while(i<n1&&j<n2)
	{
		if(l[i]<o[j])
			arr[k++]=l[i++];
		else
			arr[k++]=o[j++];
	}
	while(i<n1)
		arr[k++]=l[i++];
	while(j<n2)
		arr[k++]=o[j++];
//  	for(i=0;i<n;i++)
//		printf("%d\t",arr[i]);
//	printf("\n");
}
void merge_sort(int *arr,int beg,int end)
{
	int mid;
	/*for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");*/
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}
void display(int *arr,int n)
{
	int i;
	printf("Sorted list in ascending order:\n");
  	for(i=0;i<n;i++)
      printf("%d\n",arr[i]);
}
void main()
{
	int *arr,i,n;
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
//	printf("The steps are:\n");
	merge_sort(arr,0,n-1);
	display(arr,n);
	
}

