#include<bits/stdc++.h>
using namespace std;
/*
This keyword is a pointer to invoke variable
*/
class student{
    public:
    int roll;
    // Parametrized Constructor
    student(int roll){
        this->roll = roll;
    }
};

int main(){
    student gautam(141);
    cout<<gautam.roll<<endl;
}