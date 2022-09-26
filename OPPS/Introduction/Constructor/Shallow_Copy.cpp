// Shall copy me memeory ka addres copy hota hai
#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    int roll;
    char*name;
    char grade;
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
    gautam.name[0] = 'h'; // Shallow Copy
    gautam.print();
    rahul.print();

    return 0;

}