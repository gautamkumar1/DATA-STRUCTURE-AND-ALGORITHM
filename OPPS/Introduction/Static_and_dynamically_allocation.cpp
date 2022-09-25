#include<bits/stdc++.h>

using namespace std;

class student{
    public:
    string name;
    int roll;
};

int main(){
    student gautam; // static allocation
    gautam.name = "Gautam Kumar";
    gautam.roll = 101;
    cout<<"Name is "<<gautam.name<<endl;
    cout<<"Roll Number is "<<gautam.roll<<endl;
    student *ankush = new student; // dynamically allocation
    // delcaring using arrow operater
    ankush->name = "Ankush Kumar";
    ankush->roll = 102;
    // access using dereference operater
     cout<<"Name is "<<(*ankush).name<<endl;
    cout<<"Roll Number is "<<(*ankush).roll<<endl;
    // delcaring using arrow operater
    cout<<"Name is "<<ankush->name<<endl;
    cout<<"Roll Number is "<<ankush->roll<<endl;
    return 0;
}