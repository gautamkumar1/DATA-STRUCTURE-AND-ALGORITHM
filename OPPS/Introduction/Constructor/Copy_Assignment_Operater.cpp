#include<bits/stdc++.h>
using namespace std;

class company{
    public:
    int id;
    char*name;
    company(){
        name = new char[100];
    }
    void setid(int id){
        this->id = id;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }
    void print(){
        cout<<"Id: "<<this->id<<endl;
        cout<<"Name: "<<this->name<<endl;
        cout<<endl;
    }
};

int main(){
    company tcs;
    char name[7] = "gautam";
    tcs.setname(name);
    tcs.setid(111);
    tcs.print();
    company tcsNqt;
    char name1[5] = "Amit";
    tcsNqt.setname(name1);
    tcsNqt.setid(4444);
    tcsNqt.print();

    tcs = tcsNqt; // Copy Assignment Operater
    tcs.print();
    tcsNqt.print();
    return 0;

}