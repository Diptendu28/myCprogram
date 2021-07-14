/*Input elements in the array..Search a element in that array.. print them.[element should be present multiple times.]*/
#include<stdio.h>
int main()
{
    int array[100],s,c,n,count=0;
    printf("\nenter the size of the array: ");
    scanf("%d",&n);
    printf("\nenter the elements: ",n);
    for(c=0;c<n;c++)
    {
        scanf("%d",&array[c]);
    }
    printf("\nenter the number to search: ");
    scanf("%d",&s);
    for(c=0;c<n;c++)
    {
        if(array[c]==s)
        {
            printf("\n%d is present at loaction %d.",s,c+1);
            count++;
        }
    }
    if(count==0)
        printf("\n%d isn't present in that array.",s);
    else
        printf("\n%d is present %d times in that array.",s,count);
    return 0;
}
