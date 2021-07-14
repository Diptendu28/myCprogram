/*Create a class called time that has a separate integer member data for hours, minutes and seconds. 
One constructor should initialize this data to 0 and another should initialize it to fixed values. 
A member function should display it in HH:MM:SS format. 
The final two member functions should add and subtract two objects of time passed as arguments.
 A main() program should create two initialized time objects. Then it should add the two initialized objects,
storing the result in a third time object. Finally it should display the value of the third time object.*/

#include<bits/stdc++.h>
using namespace std;

class Time{
private:
    int h, m, s;
public:
    Time(){ h = m = s = 0;}
    Time(int hour, int min, int sec){
        h = hour;
        m = min;
        s = sec;
    }
    void display(){
         if(h<10)
            cout<<"0";
        cout<<h<<" : ";
        if(m<10)
            cout<<"0";
        cout<<m<<" : ";
        if(s<10)
            cout<<"0";
        cout<<s<<endl;
    }
    Time addtime(Time ob1, Time ob2){
        Time t;
        t.s = ob1.s + ob2.s;
        t.m = ob1.m + ob2.m;
        t.h = ob1.h + ob2.h;

        if(t.s > 59){
            t.s-=60;
            t.m++;
        }
        if(t.m > 59){
            t.m-=60;
            t.h++;
        }
        // if(t.h > 11)
        //     t.h-=12;
        
        return t;
    }
    Time subtracttime(Time ob1, Time ob2){
        Time t;
        t.s = abs(ob1.s - ob2.s);
        t.m = abs(ob1.m - ob2.m);
        t.h = abs(ob1.h - ob2.h);

        if(t.s > 59){
            t.s-=60;
            t.m++;
        }
        if(t.m > 59){
            t.m-=60;
            t.h++;
        }
        if(t.h > 11)
            t.h-=12;
        
        return t;
    }
};

int main(void){
    int h, m, s;
    cout << "Enter the hr(s): ";
    cin >> h;
    cout << "Enter the min(s): ";
    cin >> m;
    cout << "Enter the sec(s): ";
    cin >> s;
    Time t1(h, m, s);


    cout << "Enter the hr(s): ";
    cin >> h;
    cout << "Enter the min(s): ";
    cin >> m;
    cout << "Enter the sec(s): ";
    cin >> s;
    Time t2(h, m, s);

    Time t3;
    t1.display();
    t2.display();
    t3 = t3.addtime(t1, t2);
    cout << "After Addition: "<<endl;
    t3.display();
    cout << "After Subtraction: "<<endl;
    t3 = t3.subtracttime(t1, t2);
    t3.display();

    return 0;
}
