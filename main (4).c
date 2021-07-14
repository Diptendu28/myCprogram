/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*1
  31
  531
  7531
  97531*/
#include <stdio.h>

int main()
{
    int i,j;
    for(i=1;i<=9;i=i+2)
    {
        for(j=i;j>=1;j=j-2)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    
}
