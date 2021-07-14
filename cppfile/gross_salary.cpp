/*Suppose an organization has Full time and part time employee both. The full
time employee have basic pay, DA and HRA where DA is 70% of basic and HRA is
20% of basic. The part time employee have basic and overtime allowance where
overtime allowance is 1000* total overtime hours. Calculate gross salary of each
type of employee using function overloading in C++.*/
#include<iostream>
using namespace std;

void grossSalary(float a)
{
    float b,c;
    b = (0.7)*a;
    c = (0.2)*a;
	cout<<"basic salary: "<<a<<"\nDA: "<<b<<"\nHRA: "<<c<<"\nGross salary: "<<a+b+c<<endl;
}
void grossSalary(float a, int b)
{
    float c;
    c = 1000*b;
	cout<<"basic salary: "<<a<<"\nOver time salary: "<<c<<"\nGross salary: "<<a+c<<endl;
}
int main()
{
    int a,d,e;
    while(1)
	{
    	cout<<"Enter 1 for full time employee and 2 for part time employee and 0 to exit: ";
    	cin>>a;
    	if(a==0)
    		exit(0);
    	if(a == 1)
    	{
        	cout<<"Enter the basic salary: ";
        	cin>>d;
        	grossSalary(d);
    	}
    	else
    	{
        	cout<<"Enter the basic salary and the overtime hour: ";
        	cin>>d>>e;
        	grossSalary(d,e);
    	}
	}
    return 0;
}
