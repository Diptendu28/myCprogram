/*Write a c++ program to overload pre-increment, pre-decrement and post-increment, post-
decrement operator using friend function.*/
#include<iostream>
using namespace std;
class num
{
	private:
		int x,y,z;
	public:
		num(int x1=0,int y1=0,int z1=0)
		{
			x=x1;
			y=y1;
			z=z1;
		}
		void print()
		{
			cout<<"\nFirst: "<<x<<"\nsecond: "<<y<<"\nthird "<<z<<endl;
		}
		friend void operator ++(num  &ob1);
		friend void operator --(num  &ob1);
		friend void operator ++(num  &ob1,int );
		friend void operator --(num  &ob1,int );
};
void operator ++(num & ob1)
{
	ob1.x=ob1.x+1;
	ob1.y=ob1.y+1;
	ob1.z=ob1.z+1;
//	return ob1;
}
void operator --(num  &ob1)
{
	
	ob1.x=ob1.x-1;
	ob1.y=ob1.y-1;
	ob1.z=ob1.z-1;
//	return ob1;
}
void operator ++(num & ob1,int s)
{
	ob1.x=ob1.x+1;
	ob1.y=ob1.y+1;
	ob1.z=ob1.z+1;
//	return ob1;
}
void operator --(num  &ob1,int s)
{
	
	ob1.x=ob1.x-1;
	ob1.y=ob1.y-1;
	ob1.z=ob1.z-1;
//	return ob1;
}
int main()
{
	int a,b,c,x;
	cout<<"enter the three numbers: ";
	cin>>a>>b>>c;
	num ob1(a,b,c);
//	ob1.print();
//	++ob1;//preincriment
//	ob1++;
//	ob1.print();
//	--ob1;//predecrement
//	ob1--;
//	ob1.print();
	do
	{
		cout<<"enter 1 for pre-increment\nEnter 2 for pre-decrement\nEnter 3 for post-increment\nEnter 4 for post-decrement\nEnter 0 for exit\nEnter choice: ";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"pre-increment: ";
				++ob1;
				ob1.print();
				break;
			case 2:
				cout<<"pre-decrement: ";
				--ob1;
				ob1.print();
				break;
			case 3:
				cout<<"post-increment: ";
				ob1++;
				ob1.print();
				break;
			case 4:
				cout<<"post-decrement: ";
				ob1--;
				ob1.print();
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid Input\n";
		}
	}while(1);
	return 0;
}
