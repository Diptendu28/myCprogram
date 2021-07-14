/*
Create a class called Date that has separate integer members day, month and
year. One constructor should initialize these data to zero and another should
initialize to specific values. Write a main( ) function to read two dates and find
their difference in terms of the number of days and display it.
*/
#include<bits/stdc++.h>
using namespace std;

class Date{
private:
    int DD, MM, YY;
    const int months[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date():DD(0),MM(0),YY(0){}
    Date(int dd, int mm, int yy):DD(dd),MM(mm),YY(yy){}
    int diff_of_dates(Date dt1, Date dt2){
        long int A = dt1.YY * 365 + dt1.DD;
        long int B = dt2.YY * 365 + dt2.DD;

        for (int i = 0; i < dt1.MM - 1; i++)
            A += months[i];
        if(dt1.MM <= 2)
            dt1.YY--;
        A += (dt1.YY / 4 - dt1.YY / 100 + dt1.YY / 400);

        for (int i = 0; i < dt2.MM - 1; i++)
            B += months[i];
            if(dt2.MM <= 2)
            dt2.YY--;
        B += (dt2.YY / 4 - dt2.YY / 100 + dt2.YY / 400);

        return B-A;
    }
};

int main(void){ 
    int d, m, y;

	cout << "enter the day of 1st date: ";
    cin >> d;
    cout <<"enter the month of 1st date: ";
    cin >> m;
    cout <<"enter the year of 1st date: ";
    cin >> y;
    Date dt1(d, m, y);

    cout <<"enter the day of 2nd date: ";
    cin >> d;
    cout <<"enter the month of 2nd date: ";
    cin >> m;
    cout <<"enter the year of 2nd date: ";
    cin >> y;
    Date dt2(d, m, y);

    Date dt;
    cout << "Difference between two dates is "<< dt.diff_of_dates(dt1, dt2); 
  	return 0; 
}




