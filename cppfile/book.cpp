/*Consider an example of book shop which sells books and video tapes. These two
classes inherited from the base class called media. The media class has data
member such as title and publications. The book class has data members for
storing number of pages in a book and the tape class has the playing time in tape.
Each class will have member function such as read() and show() . Write a programs
which models the class hierarchy for book shop*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Media{
protected:
char publication[20],title[20];
public:
void read(char *p,char *t)
{
    strcpy(publication,p);
    strcpy(title,t);
}
void show()
{
    cout<<"publication:"<<publication<<endl;
    cout<<"title:"<<title<<endl;
}
};
class Book:public Media{
private:
int pages;
public:
void read(int page,char *p,char *t)
{
    Media::read(p,t);
    pages=page;
}
void show()
{
    cout<<"details of book:"<<endl;
    Media::show();
    cout<<"pages:"<<pages<<endl;
}
};
class Tape:public Media{
private:
int time;
public:
void read(int ti,char *p,char *t)
{
    Media::read(p,t);
    time=ti;
}
void show()
{
    cout<<"details of the tape:"<<endl;
    Media::show();
    cout<<"duration:"<<time<<endl;
}
};
int main()
{
    char t[20],p[20],t2[20],p2[20];int page,ti;
    cout<<"enter publication and title of book:"<<endl;
    cin>>p>>t;
    cout<<"enter the no. of pages:"<<endl;
    cin>>page;
    Book b;
    b.read(page,p,t);
    
    cout<<"enter publication and title of tape:"<<endl;
    cin>>p2>>t2;
    cout<<"enter the duration of tape:"<<endl;
    cin>>ti;
    Tape t1;
    t1.read(ti,p2,t2);
    b.show();
    t1.show();
    return 0;

}

/*arnab's style*/
/*#include<bits/stdc++.h>
using namespace std;

class media{
public:
    string title, publications;
    void read(){
        cout << "Enter the title: ";
        getline(cin, title);
        cout << "Enter the publication: ";
        getline(cin, publications);
    };
    void show(){
        cout << "the title: " << title << endl;
        fflush(stdin);
        cout << "the publication: " << publications << endl;
    };

};

class book: public media{
public:
    int no_of_pages;
    void read(){
        cout << "\nInput for the Book---" << endl;
        media::read();
        cout << "Enter the number of pages: ";
        cin >> no_of_pages;
    };
    void show(){
        cout << "\nOutput of the Book---" << endl;
        media::show();
        cout << "the number of pages: " << no_of_pages << " pages."<< endl;
    };

};

class tape: public media{
public:
    int playing_time;
    void read(){
        cout << "\nInput for the Tape---" << endl;
        media::read();
        cout << "Enter the duration: ";
        cin >> playing_time;
    };
    void show(){
        cout << "\nOutput of the Tape---" << endl;
        media::show();
        cout << "the number of pages: " << playing_time << " sec"<< endl;
    };
};

int main(void){
    book b1;
    tape t1;
    b1.read();
    b1.show();
    t1.read();
    t1.show();
    return 0;
}*/
