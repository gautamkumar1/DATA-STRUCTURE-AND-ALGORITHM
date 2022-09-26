#include<bits/stdc++.h>
using namespace std;
/*
Constructor is same as class name
constructor is no return type
*/

class student{
    public:
    string name;
    int roll;
    // Default Constructor
    student(){
        cout<<"I am a default contrustor"<<endl;
    }
};

int main(){
    student gautam; // static allocation
    student *gautam1 = new student(); // Dynamic allocation contsructor
    return 0;
}