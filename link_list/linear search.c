/*linear search*/
#include<stdio.h>
#include<stdlib.h>
int *arr;
int array(int n)
{
	int i;
    arr = (int*) malloc(n*sizeof(int));
    printf("\nEnter elements in the array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nThe array is :\t");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

int search(int item,int n)
{
	int i, item_present=0;
	printf("\nEnter the element to be search : ");
	scanf("%d",&item);
	
	for(i=0;i<n;i++)//for(i=0;i<=n-1;i++)
	{
			if(item==arr[i])//a[i]==item
			{
				printf("%d is present at position %d\n",item,i+1);
				item_present=1;
				break;
			}
			
	} 
	if(item_present==0)
	   printf("Sorry !!! %d is not present in the array\n",item);
}
int main()
{
	int ch,item,n;
	do
	{
		printf("\n1.Enter the array\n2.Search an element\n0.Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf ("\nEnter the number of elements : ");
    				scanf("%d",&n);
					array(n);
					break;
			case 2: search(item,n);
					break;
			case 0: exit(0);
			default:printf("\nWrong choice...please try again..");
		}
	}
	while(ch!=0);
	return 0;
}
