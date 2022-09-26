// Deep Copy : Deep copy me hum diffrent array banate hai or phir copy krte hai
#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    int roll;
    char*name;
    char grade;
    student(){
        name = new char[100];
    }
    void setroll(int roll){
        this->roll = roll;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }
    void setgrade(char grade){
        this->grade = grade;
    }

    void print(){
        cout<<endl;
        cout<<"[ ";
        cout<<"Name: "<<this->name<<" ,";
        cout<<"Garde: "<<this->grade<<" ,";
        cout<<"Roll: "<<this->roll;
        cout<<" ]";
        cout<<endl<<endl;

    }
    // Copy Constructor
    student(student&temp){
        char*ch = new char[strlen(temp.name)+1]; // Deep copy
        strcpy(ch,temp.name);
        this->name = ch;
        this->roll = temp.roll;
        this->grade = temp.grade;
    }

};

int main(){
    student gautam;
    char name[7] = "Gautam";
    gautam.setname(name);
    gautam.setroll(141);
    gautam.setgrade('A');
    gautam.print();
    // Use Default Constructor
    student rahul(gautam);
    rahul.print();
    gautam.name[0] = 'h';
    gautam.print();
    rahul.print();

    return 0;

}