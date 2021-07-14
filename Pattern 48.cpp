/*G F E D C B A
  F E D C B A
  E D C B A
  D C B A
  C B A
  B A
  A    */
#include<stdio.h>
int main()
{
    char i,a,j;
    printf("enter the alphabet");
    scanf("%c",&a);
    for(i=a;i>='A';i--)
    {
        for(j=i;j>='A';j--)
        {
            printf("%c ",j);
        }
        printf("\n");
    }
}
