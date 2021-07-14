/*Write a program to create a class shape with functions to find area of the shapes 
and display the name of the shape and other essential component of the class
.Create derived classes circle, rectangle and trapezoid each having overridden 
functions area and display. Write a suitable program to illustrate virtual functions
*/
#include<iostream>
using namespace std;
class shape
{
  protected:
    float a,b,h,r;
  public:
    virtual void area()=0;
    virtual void display()=0;
};
class circle:public shape
{
  public:
    void area()
    {
      cout<<"Enter radius of the circle"<<endl;
      cin>>r;
      a=3.14*r*r;
    }
    void display()
    {
      cout<<"Area of the circle is:"<<a<<endl;
    }
};
class rectangle:public shape
{
  public:
    void area()
    {
      cout<<"Enter length and breadth of rectangle"<<endl;
      cin>>r>>b;
      a=r*b;
    }
    void display()
    {
      cout<<"Area of the rectangle is:"<<a<<endl;
    }
};
class trapezoid:public shape
{
  public:
    void area()
    {
      cout<<"Enter the two bases and height of the trapezoid"<<endl;
      cin>>r>>b>>h;
      a=(r+b)*h*0.5;
    }
    void display()
    {
      cout<<"Area of the trapezoid is:"<<a<<endl;
    }
};
int main()
{
  int ch;
  shape *ptr;
  circle c;
  rectangle rect;
  trapezoid t;
  while(1)
  {
    cout<<"Enter 1 for circle,2 for rectangle and 3 for trapezoid"<<endl;
    cin>>ch;
    switch(ch)
    {
      case 1:ptr=&c;
      ptr->area();
      ptr->display();
      break;
      case 2:ptr=&rect;
      ptr->area();
      ptr->display();
      break;
      case 3:ptr=&t;
      ptr->area();
      ptr->display();
      break;
      case 4:exit(0);
      break;
      case 5:cout<<"Invalid Choice"<<endl;
    }
  }
}
