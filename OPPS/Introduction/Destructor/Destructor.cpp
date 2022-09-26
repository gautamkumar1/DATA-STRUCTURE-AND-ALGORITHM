#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int roll;
    ~student(){
        cout<<"Dectructor Called"<<endl;
    }
};

int main(){
    // static allocation
    student gautam;
    gautam.roll = 141;
    // dynamically allocation
    student*gautam1 = new student;
    gautam1->roll = 142;
    delete gautam1; // mannually called destructor in dynamically alloaction
}