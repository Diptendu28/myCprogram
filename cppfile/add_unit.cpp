/*Create two class DM & DB which store the value of distances.
 DM stores it in meter and Centimeter. DB store it in feet and inches. 
 Write a program that can read values for the class objects and add one object of DM with another object of DB. 
 Use a friend function to carry out the addition operation. 
 The objects that store the result may be of either type depending on the units in which the results are required. 
 The display function should act accordingly.*/
#include<iostream>
using namespace std;
class DB;
class DM
{
 	float meter,centi;
 	public:
 	void getdata()
 	{
  		cout<<"\nEnter the distance in(meter-centimeter):";
  		cin>>meter>>centi;
 	}
 	void display()
 	{
  		cout<<"\nThe distance is:";
  		cout<<meter<<" meters and "<<centi<<" centimeter";
 	}
 	friend void add(DM &,DB &);
};
class DB
{
 	float inch,feet;
 	public:
 	void getdata()
 	{
  		cout<<"\nEnter the distance in(feet-inch):";
  		cin>>feet>>inch;
 	}
 	void display()
 	{
  		cout<<"\nThe distance is:";
  		cout<<feet<<" feet and "<<inch<<" inch";
 	}
 	friend void add(DM &,DB &);
};
void add(DM &a,DB &b)
{
 	int ch,k=1;
 	float r1,r2;
 	do
	 {
// 		k=0;
 		cout<<"\nPress 1 for meter-centi";
 		cout<<"\nPress 2 for feet-inch";
 		cout<<"\npress 3 for exit\n";
 		cout<<"\nEnter your choice:";
 		cin>>ch;
// 	if(ch==1)
// 	{
//  		DM d;
//  		int c=(a.meter*100+a.centi+b.feet*30.48+b.inch*2.54);
//  		if(c>=100)
//  		{
//   			d.meter=c/100;
//   			d.centi=c%100;
//  		}
//  		else
//  		{
//   			d.meter=0;
//   			d.centi=c;
//  		}
//  		d.display();
// 	}
// 	else
// 	{
//  		DB d;
//  		int i=(a.meter*39.37+a.centi*.3937008+b.feet*12+b.inch);
//  		if(i>=12)
//  		{
//   			d.feet=i/12;
//   			d.inch=i%12;
//  		}
//  		else
//  		{
//   			d.feet=0;
//   			d.inch=i;
//  		}
//  		d.display();
// 	}
	switch(ch)
	{
		case 1:r1=a.meter+(b.feet)/3.281f;
			   r2=a.centi+(b.inch)*2.54f;
			   cout<<"Meter+Feet:"<<r1<<"meter"<<endl;
			   cout<<"Centimeter+Inch:"<<r2<<"centimeter"<<endl;
			   break;
	    case 2:r1=a.meter*3.281f+b.feet;
			   r2=a.centi/2.54f+(b.inch);
			   cout<<"Meter+Feet:"<<r1<<"feet"<<endl;
			   cout<<"Centimeter+Inch:"<<r2<<"inch"<<endl;
			   break;
		case 3: k=0;
				break;
        default:
			cout<<"Wrong Choice"<<endl;
	}
//	if(k)
//		break;
	}while(k);
}
int main()
{
 	DM a;
 	DB b;
 	a.getdata();
 	b.getdata();
 	add(a,b);
}
