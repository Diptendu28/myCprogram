/*modified bubble sort*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *b,int *c)
{
	int temp;
	temp=*b;
	*b=*c;
	*c=temp;
}
void modifiedbubblesort(int *a,int n)
{
	int i,j,flag;
	for(i=0;i<n-1;i++)
  {
    flag=0;
	for(j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
		swap(&a[j],&a[j+1]);
		flag=1;
      }
    }
    if(flag==0)
    	break;
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
  modifiedbubblesort(a,n);
  display(a,n);
  return 0;
}
