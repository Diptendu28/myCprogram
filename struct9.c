/*let us c page -302(a)*/
#include<stdio.h>
struct student
{
	int rollno; char name[30]; char dept[30]; char course[30]; int y_o_j;
};
void year(struct student [],int , int );
void details(struct student [],int , int );
void main()
{

	int i,j,n,r,y;
	printf("enter value of n:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
//		fflush(stdin);
		printf("\n Name: ");
		scanf("%s",&s[i].name);
//		fflush(stdin);
		printf("\n roll no: ");
		scanf("%d",&s[i].rollno);
//		fflush(stdin);
		printf("\n Department: ");
		scanf("%s",&s[i].dept);
//		fflush(stdin);
		printf("\n Course: ");
		scanf("%s",&s[i].course);
//		fflush(stdin);
		printf("\n Year of joining: ");
		scanf("%d",&s[i].y_o_j);	
//		fflush(stdin);
	}
	printf("\nDetails entered:");
	for(i=0;i<n;i++)
	{
		printf("\nName=%s Roll.no=%d Department=%s Course=%s Year of joining=%d",s[i].name,s[i].rollno,s[i].dept,s[i].course,s[i].y_o_j);
	}
	printf("\nenter roll no:");
	scanf("%d",&r);
	details(s,r,n);
	printf("\n enter year of joining :");
	scanf("%d",&y);
	year(s,y,n);
}
void details(struct student stud[], int r, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
			if(stud[i].rollno==r)
			{
				printf("\nName=%s Roll.no=%d Department=%s Course=%s Year of joining=%d",stud[i].name,stud[i].rollno,stud[i].dept,stud[i].course,stud[i].y_o_j);
			}
	}
}
void year(struct student stud[], int y,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
			if(stud[i].y_o_j==y)
			{
				printf("\nName=%s Roll.no=%d Department=%s Course=%s Year of joining=%d",stud[i].name,stud[i].rollno,stud[i].dept,stud[i].course,stud[i].y_o_j);
			}
	}
}
