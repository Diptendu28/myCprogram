/*Factorial of multi number using command line argument*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	int n,i,j,p;
	for(i=1;i<argc;i++)
	{
		int flag=1;
		for(j=0;j<strlen(argv[i]);j++)
		{
			if(argv[i][j]>='0'&& argv[i][j]<='9')
				continue;
			else
			{
				printf("invalid output\n");
				flag=0;
			}
		}
		if(flag)
		{
			int h=atoi(argv[i]);
			if(h<=0)
			{
				if(!h)
					printf("0!=1\n");
				continue;
			}
			int f=1;
			for(p=1;p<=h;p++)
				f=f*p;
			printf("%d!=%d\n",h,f);
		}
	}
	return 0;
}
