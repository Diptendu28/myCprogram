/* binary search of a number by its position */
#include<stdio.h>
#include<stdlib.h>
void bubblesort(int *b,int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(b[j]>b[j+1])
      {
		temp=b[j];
        b[j]=b[j+1];
        b[j+1]=temp;
      }
    }
  }
}
void binarysearch(int *c,int n,int s)
{
	int start,end,mid,f=0;
	start=0;
	end=n-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(s==c[mid])
		{
			printf("found at %d position",mid+1);
			f=1;
			break;
		}
		if(s>c[mid])
			start=mid+1;
		if(s<c[mid])
			end=mid-1;
	}
	if(f==0)
	printf("\nnot found");
}
int main()
{
  int *a,n,i,d,s;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  printf("Enter %d integers\n",n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  bubblesort(a,n);
  printf("Sorted list in ascending order:\n");
  for(i=0;i<n;i++)
     printf("%d\n",a[i]);
  printf("enter no to search\n");
  scanf("%d",&s);
  binarysearch(a,n,s);
  return 0;
}

