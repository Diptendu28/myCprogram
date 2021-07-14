#include<iostream>
#include<stdlib.h>
using namespace std;
class Person{
    public:
    string name;
    void getDetails()
    {
        cout<<"enter name:"<<endl;
        cin>>name;
    }
    void printDetails()
    {
        cout<<"name: "<<name;
    }
};
class Student:public virtual Person{
};
class Employee:public virtual Person{
};
class Manager:public Student,public Employee{
};
int main()
{
    Manager m;
    m.getDetails();
    m.printDetails();
    return 1;
}

/*Create a class Person and two derived classes Employee, and Student, inherited from class Person. 
Now create a class Manager which is derived from two base classes Employee and Student. 
Show the use of the virtual base class.*/

