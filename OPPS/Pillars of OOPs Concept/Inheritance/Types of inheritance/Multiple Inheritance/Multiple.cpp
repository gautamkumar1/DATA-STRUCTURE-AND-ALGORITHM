#include<iostream>
using namespace std;

class Animal{
    public:
    void barks(){
        cout<<"Barking...."<<endl;
    }
};

class Human{
    public:
    void speak(){
        cout<<"Speaking...."<<endl;
    }
};

// Multiple Inheritance

class Hybrid : public Animal , public Human{
    public:
    void greeting(){
        cout<<"Yahooo"<<endl;
    }
};

int main(){
    Hybrid obj1;
    obj1.barks();
    obj1.speak();
    return 0;
}