/*merging of two sorted and unsorted array in a third array (sorted order) */
#include<stdio.h>
#include<stdlib.h>
int main()
{
 	int s1,s2,mSize,i,j,temp;
	int *a,*b,*Marray;
  	printf("\n Please Enter the First Array Size :  ");
 	scanf("%d",&s1);
 	a=(int*)malloc(s1*sizeof(int));
 	printf("\nPlease Enter the First Array Elements:  ");
 	for(i=0;i<s1;i++)
      	scanf("%d",&a[i]);
  	printf("\n Please Enter the Second Array Size :  ");
 	scanf("%d",&s2);
 	b=(int*)malloc(s2*sizeof(int));
   	printf("\nPlease Enter the Second Array Elements :  ");
 	for(i=0;i<s2;i++)
      	scanf("%d",&b[i]);
  	mSize=s1+s2;
  	Marray=(int*)malloc((s1+s2)*sizeof(int));
	i=0;
	j=0;
	for(i=0;i<s1;i++)
		Marray[i]=a[i];
	for(j=0;j<s2;j++)
		Marray[i++]=b[j];
 //sorting potion// 	
	for(i=0;i<mSize;++i) 
    {
 		for(j=i+1;j<mSize;++j)
    	{
 			if(Marray[i]>Marray[j]) 
            {
 				temp=Marray[i];
                Marray[i]=Marray[j];
                Marray[j]=temp;
 			}
		}
	}
	printf("\nArray Elements After Merging\n"); 
 	for(i=0;i<mSize;i++)
    	printf(" %d \t ",Marray[i]);
	return 0;
}
