/*complex number addition*/
#include<bits/stdc++.h>
using namespace std;

class Complex{    
public: 
int r,i;
    void getValue(int r1, int i1){
       r = r1;
       i = i1;
    }
    void print(){
        cout << r <<" + j" <<i;
    }
    void addcomplex(int r1, int r2, int i1, int i2){
        r = r1 + r2;
        i = i1 + i2;
    }
};

int main(void){
    Complex ob1, ob2, ob;
    int r, i;
    cout << "Enter the real and img part of 1st number: ";
    cin >> r >> i;
    ob1.getValue(r, i);
    cout << "Enter the real and img part of 2nd number: ";
    cin >> r >> i;
    ob2.getValue(r, i);
    ob.addcomplex(ob1.r, ob2.r, ob1.i, ob2.i);
    ob1.print();
    ob2.print();
    cout << " = ";
    ob.print();
    return 0;
}
