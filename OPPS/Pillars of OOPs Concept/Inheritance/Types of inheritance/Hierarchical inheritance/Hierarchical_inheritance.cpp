#include<iostream>
using namespace std;

class A{
    public:
    void meth1(){
        cout<<"Calling From Class A"<<endl;
        cout<<"I am method1"<<endl;
    }
};

class B : public A{
    public:
    void meth2(){
        cout<<"Calling From Class B"<<endl;
        cout<<"I am method2"<<endl;
    }
};

class C : public A{
    public:
    void meth3(){
        cout<<"Calling From Class C"<<endl;
        cout<<"I am method3"<<endl;
    }
};

int main(){
    A obj1;
    obj1.meth1();
    B obj2;
    obj2.meth1();
    obj2.meth2();
    C obj3;
    obj3.meth1();
    obj3.meth3();
    return 0;
}