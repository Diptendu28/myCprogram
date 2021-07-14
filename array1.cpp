/* input 10 numbers in an array. input another number and search that number in that array */
#include<stdio.h>
int main()
{
	int i,s,a[10],f=0;
	for(i=0;i<10;i++)
	{
		printf("\nenter no: ");
		scanf("%d",&a[i]);
	}
	printf("\nenter no to search: ");
	scanf("%d",&s);
	for(i=0;i<10;i++)
	{
		if(s==a[i])
		printf("\nfound at %d",i);
		f=1;
	}
	if(f==0)
	printf("\nnot found");
}
	
	

