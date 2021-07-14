/*write a simple program that convert the temp in degreecelcius to degree farenheut.
and vice versa using the basic concept of class and object.Make separate class for centrigrade
and farenheit which will have the private member to hold the temperature value and make conversion func in each
class for conversion from one to other. For example you will have func to farenheit in class celcius that converts
to farenheit scale and returns the value.*/
#include<bits/stdc++.h>
using namespace std;

class Celsius{
private:
    float celsius_val;
public:
    void setValue(float celsius){
        celsius_val = celsius;
    }
    float toFahrenheit(){
        return (celsius_val * 9 / 5) + 32;
    }
};

class Fahrenheit{
private:
    float fahrenheit_val;
public:
void setValue(float fahrenheit){
        fahrenheit_val = fahrenheit;
    }
    float toCelsius(){
        return ((fahrenheit_val - 32) * 5) / 9;
    }
};

int main(void){
    float val;
    while(1){
        int opt;
        cout << "\n0 to stop\n1 for C to F\n2 for F to C\n\nchoose: ";
        cin >> opt;
        switch(opt){
            case 0: exit(0);
            case 1: Celsius celsius;
                    cout << "Enter the temp(in Celsius): ";
                    cin >> val;
                    celsius.setValue(val);
                    cout << "Celsius to Fahrenheit: " << celsius.toFahrenheit() << endl;
                    break;
            case 2: Fahrenheit fahrenheit;
                    cout << "Enter the temp(in Fahrenheit): ";
                    cin >> val;
                    fahrenheit.setValue(val);
                    cout << "Fahrenheit to Celsius: " << fahrenheit.toCelsius() << endl;
                    break;
            default : cout << "Invalid Option!!!"<<endl;
        }
    }
    return 0;
}
