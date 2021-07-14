/*Implement a class called Tool. It should have an int field called strength and a char field called type. 
 You may make them either private or protected. The Tool class should also contain the function void setStrength(int), 
 which sets the strength for the Tool.
 Create 3 more classes called Rock, Paper, and Scissors, which inherit from Tool. 
 Each of these classes will need a constructor which will take in an int that is used to initialize the strength field. 
 The constructor should also initialize the type field using 'r' for Rock, 'p' for Paper, and 's' for Scissors.
 These classes will also need a public function bool fight(Tool) that compares their strengths in the following way:
 Rock's strength is doubled (temporarily) when fighting scissors, but halved (temporarily) when fighting paper.
 In the same way, paper has the advantage against rock, and scissors against paper.
 The strength field shouldn't change in the function, 
 which returns true if the original class wins in strength and false otherwise.*/

#include<bits/stdc++.h>
using namespace std;

class tool{
public:
    int strength;
    char type;
    void setStrenght(int val){
        strength = val;
    }
};

class rock : public tool{
public:
    rock(int x){
        strength = x;
        type = 'r';
    }
    bool fight(tool &t){
        if(t.type == 's')
            this->strength *= 2;
        if(t.type == 'p'){
            this->strength /= 2;
            return false;
        }
        return true;
    }
};

class paper : public tool{
public:
    paper(int x){
        strength = x;
        type = 'p';
    }
    bool fight(tool &t){
        if(t.type == 'r')
            this->strength *= 2;
        if(t.type == 's'){
            this->strength /= 2;
            return false;
        }
        return true;
    }
};

class scissors : public tool{
public:
    scissors(int x){
        strength = x;
        type = 's';
    }
    bool fight(tool &t){
        if(t.type == 'p')
            this->strength *= 2;
        if(t.type == 'r'){
            this->strength /= 2;
            return false;
        }
        return true;
    }
};


int main(void){
    paper p(1);
    rock r(1);
    scissors s(1);

    cout << std::boolalpha      //std::noboolalpha
        << p.fight(r) << endl
        << p.fight(p) << endl     
        << p.fight(s) << endl

        << r.fight(r) << endl
        << r.fight(p) << endl
        << r.fight(s) << endl

        << s.fight(r) << endl
        << s.fight(p) << endl
        << s.fight(s);

    return 0;
}

/*
Output
-------

true
true
false
true
false
true
false
true
true

*/


