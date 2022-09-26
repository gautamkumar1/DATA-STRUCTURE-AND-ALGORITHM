#include<bits/stdc++.h>

using namespace std;

class student{
    private: 
    int roll;
    public:
    string name;
    void print(){
        cout<<"Roll: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
    }
    void setRoll(int roll){
        this->roll = roll;
    }
    void setName(string name){
        this->name = name;
    }
    int getRoll(){
        return roll;
    }
    string getName(){
        return name;
    }
    student(int roll,string name){
        this->roll = roll;
        this->name = name;
    }
    // Copy constructor
    student(student &temp){
        cout<<"I am a copy constructor"<<endl;
        this->name = temp.name;
        this->roll = temp.roll;
    }

};

int main(){
    student gautam(141,"Gautam Kumar");
    gautam.print();
    student addrash(gautam); // Default copy constructor
    addrash.print();
    return 0;
}