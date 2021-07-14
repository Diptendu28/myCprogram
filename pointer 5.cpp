/*Write a program in C to store n elements in an array and print the elements using pointer.*/
#include <stdio.h>
int main()
{
    int a[100],n,i;
    int *ptr=a;   
	printf("\nenter size of array:");
    scanf("%d",&n);
	printf("enter elements in array:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",ptr);
        ptr++;   
    }
    ptr=a;
	printf("array elements are:");
    for (i=0;i<n;i++)
    {
        printf("%d ",*ptr);
        ptr++;
    }
    return 0;
}
