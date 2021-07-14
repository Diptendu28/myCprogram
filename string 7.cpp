/*There is a string,followed by which there is a number.Check the odd indexes of the number and make that square of each digit of odd placed.
Then add them.And if the addition is lesser than 200,flip the string...*/
#include<string.h>
#include<math.h>
int main()
{
	char str[100];
	int i=0,sum=0,c=1;
	printf("Enter the name with space followed by a number: ");
	gets(str);
	while(str[i]!=' ')
		i++;
	i++;
	while(str[i])
	{
		if(c%2)
		{
		   if(c!=1)
		    printf("+");
		   printf("%d^2",str[i]-'0');
		   sum=sum+pow(str[i]-'0',2);
		}
		c++;
		i++;
	}
	printf("=%d",sum);
	printf("\nSo the name is: ");
	i=0;
	if(sum<200)
	{
		while(str[i]!=' ')
		  i++;
		i--;
		while(i>=0)
			printf("%c",str[i--]);
	}
	else
		while(str[i]!=' ')
			printf("%c",str[i++]);
	return 0;
}
