/*sum of 1st n natural numbers.....like 5-> 5+4+3+2+1=15*/
#include <stdio.h>
int addNumbers(int n);
int main() 
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for(int i=num;i>0;i--)
    {
    	if(i!=1)
    		printf("%d+",i);
    	else
    		printf("%d",i);
	}
    printf("=%d", addNumbers(num));
    return 0;
}

int addNumbers(int n)
{
    if (n != 0)
        return n + addNumbers(n - 1);
    else
        return n;
}
