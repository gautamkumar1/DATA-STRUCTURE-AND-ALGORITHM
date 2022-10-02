#include<iostream>
using namespace std;

class grandfather{
    public:
    string name;
    void principle(){
        cout<<"Grandfather is a principle"<<endl;
    }
};

class father : public grandfather{
    public:
    void hod(){
        cout<<"Father is hod"<<endl;
    }
};

class child : public father{
    void allInOne(){
        cout<<"Child is all in one"<<endl;
    }
};

int main(){
    child pranit;
    pranit.name = "Gautam";
    pranit.hod();
    pranit.principle();
    return 0;
}