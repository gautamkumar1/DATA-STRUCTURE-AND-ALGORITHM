/*
single inheritance : A 
                     |
                     B
*/

#include<iostream>
using namespace std;

class animal{
    public:
    string name;
    int age;
    void print(){
        cout<<"Name of Dog is "<<this->name<<endl;
        cout<<"Age of Dog is "<<this->age<<endl;
    }
};

class dog : public animal{
    public:
    void barks(){
        cout<<"Bhoo...Bhooo"<<endl;
    }
};

int main(){
    dog obj;
    obj.name = "Pranit";
    obj.age = 20;
    obj.print();
    obj.barks();
    return 0;
}