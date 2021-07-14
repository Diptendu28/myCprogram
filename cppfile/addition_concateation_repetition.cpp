/*Write a C++ program to overload binary + for following operation,
i. If + apply on numbers perform addition of two number.
ii. If + apply on Strings perform concatenation.(Consider an user defined
String class).
iii. If + apply on String and number perform String repetition.(i.e
Str+2:HelloHello if Str contained “Hello”)
*/
#include<bits/stdc++.h>
using namespace std;
class String
{
	private:
		string str;
	public:
		void constructor(string s)
		{
			str=s;
		}
		friend string operator +(String s, int x);
		friend string operator +(String s1, String s2);
};

string operator + (String s, int x)
{
    string temp = "\0";
    while(x--)
        temp.append(s.str);
    return temp;
}

string operator + (String s1, String s2)
{
	return s1.str+s2.str;
}

int main()
{
	String str,str1;
	string s;
	int flag=1,num,num1;
	while(flag)
	{
		int val;
		cout<<"\n0 for exit\n1 for addition of two number\n2 perform concatenation of two string\n3 for perform string repetition\nchoose: ";
		cin>>val;
		switch(val)
		{
			case 0: 
				flag=0;
			break;
			case 1:
				cout<<"enter 1st number: ";
				cin>>num;
				cout<<"enter 2nd number: ";
				cin>>num1;
				cout<<num + num1<<endl;
			break;
			case 2:
				cout<<"enter 1st string: ";
				cin>>s;
				str.constructor(s);
				cout<<"enter 2snd string: ";
				cin>>s;
				str1.constructor(s);
				cout<< str + str1 <<endl;
			break;
			case 3:
				cout<<" enter the string: ";
				cin>>s;
				str.constructor(s);
				cout<< "enter the number: ";
				cin>> num;
				cout<< str + num << endl;
			break;
			default:
				cout<< "Invalid input!!";
		}
	}
	return 0;
}

