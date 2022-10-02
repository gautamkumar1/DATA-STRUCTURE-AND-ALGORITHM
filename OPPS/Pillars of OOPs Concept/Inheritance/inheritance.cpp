/*
syntax: class_name:access_modifier parebtclassName;
*/
#include<iostream>
using namespace std;
class Human{
    public:
    int age;
    int weight;
    int getage(){
        return this->age;
    }
};
// Inheritance
class male: public Human{
    public:
    string name;
    string color;
};

int main(){
    male gautam;
    gautam.age = 14;
    gautam.name = "Gautam";
    gautam.color = "Black";
    gautam.weight = 80;
    cout<<gautam.name<<endl;
    cout<<gautam.getage()<<endl;
    cout<<gautam.color<<endl;
    cout<<gautam.weight<<endl;
    return 0;
}