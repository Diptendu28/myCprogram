/*Write a c program to define a structure employee containing employee's id name designation salary and year of joining.
Take the details of 3 employees from user and print those details after that find out the name of the highest paid employee and senior most employee.*/
#include<stdio.h>
#include<string.h>
struct employee
{
	int d,m,y;
	char code[10],name[10];
	int salary;
};
int main()
{
 	struct employee emp[10];
	int n,i,j,high,min;
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
		fflush(stdin);
   		printf("Enter Employer Name : ");
   		gets(emp[i].name);
   		printf("Enter joining year : ");
   		scanf("%d",&emp[i].y);
   		printf("enter the salary : ");
   		scanf("%d",&emp[i].salary);
  	}
	high=emp[0].salary;
    for(i=0;i<n;i++)
    {
        if(emp[i].salary>high)
        	high=emp[i].salary;
    }
    printf("Highest salary employee details:");
    for(i=0;i<n;i++)
    {
        if(emp[i].salary==high)
        	printf("\n %s\t%s\t%d",emp[i].code,emp[i].name,emp[i].salary);
    }
    min=emp[0].y;
    for(i=0;i<n;i++)
    {
    	if(emp[i].y<min)
    		min=emp[i].y;
	}
	printf("\nsenior most employee's name: ");
	for(i=0;i<n;i++)
    {
    	if(emp[i].y==min)
    		printf("%s\n",emp[i].name);
    }
    return 0;
 }
