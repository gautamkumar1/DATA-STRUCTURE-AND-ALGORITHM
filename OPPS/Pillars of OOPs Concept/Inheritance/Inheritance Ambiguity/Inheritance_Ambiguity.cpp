#include<iostream>
using namespace std;

class A{
    public:
    void func(){
        cout<<"Calling From A Class"<<endl;
    }
};

class B{
    public:
    void func(){
        cout<<"Calling From B Class"<<endl;
    }
};

class C : public A,public B{

};

int main(){
    C obj;
    // Syntax : object_name.Class_Name::Function_name
    obj.A::func();
    obj.B::func();
    return 0;
}