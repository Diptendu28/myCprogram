/*	*
   * *
  *   *
 *     *     *
        *   *
         * *
          *    */
#include <stdio.h>
int main()
{
    int a,i,j;
	printf("Enter the amplitude: \n");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
  		for(j=i;j<a-1;j++)//printing the left side spaces of the positive half
       		printf(" ");
  		printf("*");
       	if(i==0)//topmost row will have only one star
            printf("\n");
        if(i!=0)//other rows will have two stars
  		{
      		for(j=0;j<=2*i-2;j++)//printing the middle spaces of the positive half
           		printf(" ");
            printf("*");
            if(i!=a-1)
           		printf("\n");
  		}
       if(i==a-1)//just printing the first line of the negative half in the last line of positive half
       {
            for(j=0;j<=2*i-2;j++)
           		printf(" ");
      		printf("*\n");
       }
	}
	for(i=a-1;i>0;i--)
    {
        for(j=0;j<2*a-1;j++)//just to pass the first half spaces
           printf(" ");
  		for(j=i;j<a-1;j++)//to give the left front spaces of negative half
            printf(" ");
        printf("*");
        if(i!=1)
        {
            for(j=0;j<2*i-3;j++)//middle spaces
               printf(" ");
          	printf("*\n");
        }
    }
	return 0;
}



