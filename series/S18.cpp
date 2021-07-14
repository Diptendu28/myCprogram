/*A       Z       X       B       V       T       C       R......*/
#include<stdio.h>
int main()
{
    int i=1,n,a=65,b=90;
    printf("enter no");
    scanf("%d",&n);
    while(i<=n)
    {
        if(i%3==1)
        {
        	printf("%c\t",a++);
		}
        if(i%3==2)
        {
        	printf("%c\t",b);
			b=b-2;	
		}
        if(i%3==0)
        {
        	printf("%c\t",b);
        	b=b-2;
		}
		i++;
    }
    
}  
