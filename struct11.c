/*There is a structure called employee that holds information like employee code, 
name, date of joining. Write a program to create an array of the structure and enter some data into it. 
Then ask the user to enter current date. Display the names of those employees whose 
tenure is 3 or more than 3 years according to the given current date. LET US C, PAGE -303(E) */
#include<stdio.h>
#include<string.h>
struct employee
{
	int d,m,y;
	char code[10],name[10];
};
int main()
{
 	struct employee emp[10];
	int n,i,j,dd,mm,yy;
 	printf("Enter numbers of Employees : ");
 	scanf("%d",&n);
  	for(i=0;i<n;i++)
  	{
   		while(1)
   		{
   			printf("\nEnter Emp Code : ");
   			scanf("%s",emp[i].code);
			int flag=0;
			for(j=0;j<i;j++)
			{
				if(strcmp(emp[i].code,emp[j].code)==0)
				{
					flag=1;
					printf("please give a unique code.");
				}
			}
			if(flag==0)
				break;
		}
   		printf("Enter Employer Name : ");
   		scanf("%s",emp[i].name);
   		printf("Enter joining  Date (dd mm yy) : ");
   		scanf("%d%d%d",&emp[i].d,&emp[i].m,&emp[i].y);
  	}
  	printf("\nEnter current Date : ");
  	scanf("%d%d%d",&dd,&mm,&yy);
 	for(i=0;i<n;++i)
	{
 		if((yy-emp[i].y)>=3)
 		printf("\nCode : %s : Name : %s : Date of Joining : %d/%d/%d",emp[i].code,emp[i].name, emp[i].d,emp[i].m,emp[i].y);
	}
 	return 0;
}
