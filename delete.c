/*delete*/
#include <stdio.h>
void main()
{
    int a[10],i,n,pos,no,c=0,flag=1;
 	printf("Enter size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
 	for (i=0;i<n;i++)
        scanf("%d",&a[i]);
 	printf("Enter the element to be deleted\n");
    scanf("%d",&no);
    while(flag) {flag=0;
 	for(i=0;i<n-c;i++)
    {
        if(a[i]==no)
        {
            flag=1;
            pos=i;
            break;
        }
    }
 	if(flag==1)
    {
    	c++;
        for (i=pos;i<n-1;i++){
        	a[i]=a[i+1];
		}
    }}
    if(c) {
    printf("the final array is\n");
        for (i=0;i<n-c;i++)
        	printf("%d\n",a[i]);
		}
    else
        printf("Element %d is not found in the array\n",no);
}
