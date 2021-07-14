#include <stdio.h>
int main()
{
    int a[50],n,pos,i,item;
    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i=0;i<n;i++)    
    	scanf("%d",&a[i]);
    printf("Please enter the location where you want to insert an new element\n");
    scanf("%d",&pos);
    printf("Please enter the value\n");
    scanf("%d",&item);
    for (i=n-1;i>=pos-1;i--)    
		a[i+1]=a[i];
    a[pos-1]=item;
    printf("Final array is\n");
    for (i=0;i<=n;i++)    
		printf("%d\n",a[i]);    
    return 0;
}
