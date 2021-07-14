/*Write a program to check whether a given input string contain only alphabet or
not. If invalid input then throw an exception and handle it by appropriate catch
block.*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i;
	string st;
	do
	{
		cout<<"enter the string:"<<endl;
		getline(cin,st);
		try
		{
			if(st.length()==1)
				throw 1;
			for(i=0;i<st.length();i++)
			if((st[i]>='A'&& st[i]<='Z')||(st[i]>='a'&&st[i]<='z')||st[i]==' ')
				continue;
			else
				throw 'a';
			cout<<"correct input."<<endl;
			break;
		}
		catch(int y)
		{
			cout<<"one character."<<endl;
		}
		catch(char a)
		{
			cout<<"string shouldcontain alp."<<endl;
		}
	}while(1);
	return 0;
}
