/*let us c page-302 (b)*/
#include<stdio.h>
#include<string.h>
struct customer
{
	int acc_no; char name[30]; float balance;
};
void insufficient_balance(struct customer[],int );
void withdraw(struct customer[],int ,float ,int);
void deposit(struct customer[],int ,float ,int);
void main()
{
	int i,n,no,code;
	char consent;
	float dummy,a;
	printf("enter value of n:");
	scanf("%d",&n);
	struct customer c[n];
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\n Account no:");
		scanf("%d",&c[i].acc_no);
//		fflush(stdin);
		printf("\n Name:");
		gets(c[i].name);
//		fflush(stdin);
		printf("\n Account balance:");
		scanf("%f",&dummy);
//		fflush(stdin);
		c[i].balance=dummy;
	}
	printf("\nDetails of all customers:");
	for(i=0;i<n;i++)
	{
		printf("\nAccount number=%d name=%s Account balance=%.2f",c[i].acc_no,c[i].name,c[i].balance);
	}
	printf("\ncustomers with low balance:");
	insufficient_balance(c,n);
	printf("\nDo you want to withdraw or deposit money? ");
	scanf("%c",&consent);
	if(consent=='y')
	{
		printf("\nAccount number: ");
		scanf("%d",&no);
		printf("\namount:");
		scanf("%f",&a);
		printf("\ncode:");//1 for deposit, 0 for withdarwal//
		scanf("%d",&code);
	}
	else
	{
		printf("\nThank you");
	}
	switch(code)
	{
		case 1: printf("\ndeposit money");
				deposit(c,no,a,n);
				break;
		case 0:printf("\nwithdraw money");
				withdraw(c,no,a,n);
				break;
		default:printf("\ninvalid code");
	}
	
}
void insufficient_balance(struct customer account[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(account[i].balance<100)
		{
			printf("\nAccount number=%d Name=%s",account[i].acc_no,account[i].name);
		}
	}
}
void withdraw(struct customer c[],int no,float a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(c[i].acc_no==no)
		{
			c[i].balance=c[i].balance-a;
			if(c[i].balance<100)
			{
				printf("\nThe balance is insufficient for the specified withdrawal");
			}
			else
			{
				printf("\nFinal balance=%.2f",c[i].balance);
			}
		}
	}
}
void deposit(struct customer c[],int no,float a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(c[i].acc_no==no)
		{
			c[i].balance=c[i].balance+a;
			printf("\nFinal balance=%.2f",c[i].balance);
		}
	}
}

