#include<stdio.h>
int main() 
{
	int a[10],n,item,i,item_present=0;
	
	printf("Enter size of the array<=10:");
	scanf("%d",&n);
	
	printf("Enter elements in the array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Enter the element to be search:");
	scanf("%d",&item);
	
	for(i=0;i<n;i++)//for(i=0;i<=n-1;i++)
	{
			if(item==a[i])//a[i]==item
			{
				printf("%d is present at position %d",item,i+1);
				item_present=1;
				break;
			}
			
	} 
	if(item_present==0)
	   printf("Sorry !!! %d is not present in the array",item);
	return 0;
}