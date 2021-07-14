/* EEEEEEEEE
   ESSSSSSSE
   ESUUUUUSE
   ESUOOOUSE
   ESUOMOUSE
   ESUOOOUSE
   ESUUUUUSE
   ESSSSSSSE
   EEEEEEEEE */
#include<stdio.h>
int main()
{
	char a[9][9],i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(i==0||j==0||i==8||j==8)
				a[i][j]='E';
			else if(i==1||j==1||i==7||j==7)
				a[i][j]='S';
			else if(i==2||j==2||i==6||j==6)
				a[i][j]='U';
			else if(i==3||j==3||i==5||j==5)
				a[i][j]='O';
			else
				a[i][j]='M';
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
