#include<iostream>
using namespace std;
/*
Class ke andar by default koii bhi properties private rhta hai
*/
// Creating Class
class Student {
    // Properties
    private: // Public ke niche jitne bhi rahenge woh sab public rahega
    int rollNumber; 
    public: // Private ke niche jitne bhi rahenge woh sab public rahega
    string name;
    // Creating setter for roll number
    void setRoll(int r){
        rollNumber = r;
    }
    // Creating getter for Roll Number
    int getRoll(){
        return rollNumber;
    }
    // Creating setter for Name
    void setName(string n){
        name = n;
    }
    // Creating getter for Name
    string getName(){
        return name;
    }
};

int main(){
    // Creating object
    Student Gautam; // Size of blank object is always one
    // With getter and setter
    cout<<"Using getter and setter"<<endl;
    Gautam.setName("Gautam Kumar");
    Gautam.setRoll(141);
    cout<<"My Name is : "<<Gautam.getName()<<endl;
    cout<<"Roll number is: "<<Gautam.getRoll()<<endl;
    /* 
    Gautam.rollNumber = 141;
    Gautam.name = "Gautam Kumar";
    
    --> Without Getter and setter
    cout<<"My Name is : "<<Gautam.name<<endl;
    cout<<"Roll number is: "<<Gautam.rollNumber<<endl;
    // cout<<"Size: "<<sizeof(Gautam)<<endl;
    */
    return 0;
}