/*Create a class String then implement the following operation
i.	Overload the + operator for string concatenation. 
ii.	 Overload the ? operator for subtract the length of two string. 
iii.            Overload the < operator for string comparison.*/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
    private:
    char s[20];
    public:
    String()
    {
        s[0]='\0';
    }
    String(char *str){
    	strcpy(s,str);
	}
    String operator +(const String &ob1)
    {
        String ob3;
        strcpy(ob3.s,s);
        strcat(ob3.s,ob1.s);
        return ob3;
    }
    int operator -(const String &ob1){
    	return strlen(s)-strlen(ob1.s);
	}
    int operator <(const String &ob1){
    	return (strcmp(s,ob1.s)<0)?1:0;
	}
    void print(){
    	cout<<s;
	}
        
};
int main()
{
    char s[20],s1[20];
    cout<<"enter the string:"<<endl;
    cin>>s;
    String ob(s);
    cout<<"enter the string:"<<endl;
    cin>>s1;
    String ob1(s1);
    String ob3=ob+ob1;
    cout << "the two string after concatenation is ";
    ob3.print();
    cout<<"\ndiff in length is "<<ob-ob1<<endl;
    if(ob<ob1)
    {
        cout<<"\nFirst string "; 
        ob.print(); 
        cout << " is lesser than second string ";
        ob1.print();
    }
    else
    {
        cout<<"\nFirst string ";
        ob.print(); 
        cout << " is greater than or equal to second string ";
        ob1.print();
    }
    return 0;
}


/*arnab's style*/
/*#include<bits/stdc++.h>
using namespace std;

class String{
private:
    string str;
public:
    void set_string(string s){ str = s; }
    friend string operator + (String &str1, String &str2);
    friend int operator - (String &str1, String &str2);
    friend int operator < (String &str1, String &str2);
    string display(String &s){ return s.str; }
};

string operator + (String &str1, String &str2)
{
    String ob;
    ob.str = str1.str;
    ob.str.append(str2.str);
    return ob.str;
}

int operator - (String &str1, String &str2)
{
    int val = str1.str.length() - str2.str.length();
    return abs(val);
}

int operator < (String &str1, String &str2){
    return  (str1.str.compare(str2.str) < 0) ? 1 : 0;
}

int main(void){
    String ob1, ob2;
    string str;
    int flag = 1;
    while(flag){
        int val;
        cout << "\n0 to exit\n1 for string concatenation\n2 for subtract the length of two string\n3 for string comparison\nchoose: ";
        cin >> val;
        if(!val){flag = 0; continue;}
        cout << "enter the 1st string: ";
        cin >> str;
        ob1.set_string(str);
        cout << "enter the 2nd string: ";
        cin >> str;
        ob2.set_string(str);
        switch(val){
            case 1: cout << endl << ob1 + ob2 << endl; break;
            case 2: cout << endl << ob1 - ob2 << endl; break;
            case 3: 
                if(ob1 < ob2)
                    cout << ob1.display(ob1) << " < " << ob2.display(ob2);
                else
                    cout << ob1.display(ob1) << " >= " << ob2.display(ob2);
            break;
            default: cout << "invalid choice!!!";
        }
    } 
    return 0;
}*/
