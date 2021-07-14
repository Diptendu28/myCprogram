/* Write a program in C to count a total number of duplicate elements in an array using function.*/
#include<stdio.h>
int dup(int a[],int l)
{
	int i,j,ct=0;
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(a[i]==a[j])
            {
                ct++;
                break;
            }
        }
    }
	return ct;
}
int main()
{
    int a[100];
    int i,j,l,ct=0;
    printf("\nenter the size of the array: ");
    scanf("%d",&l);
    printf("\nenter elements in array: ");
    for(i=0;i<l;i++)
    {
    	scanf("%d",&a[i]);
    }
    ct=dup(a,l);
    printf("\ntotal number of duplicate elements = %d",ct);
	return 0;
}

