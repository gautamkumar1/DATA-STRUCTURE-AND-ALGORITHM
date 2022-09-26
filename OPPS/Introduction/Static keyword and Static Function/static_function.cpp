// static_functin me object krne ki need nhi hai
// static function ke paas 'this keyoword' nhi hota hai kyuki this keyword pointer to object hota hai isliye woh nhi hota hai
// static function sirf static member ko hi access kr skte hai
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int roll;
    char garde;
    static int id;
    // static function
    static int printStatic(){
        return id;
    }
};

int student ::id = 141;
int main(){
    cout<<student::printStatic()<<endl;
    return 0;
}