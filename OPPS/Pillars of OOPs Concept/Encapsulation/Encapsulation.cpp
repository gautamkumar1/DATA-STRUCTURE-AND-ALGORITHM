/*
Encapsulation is wrapping data memeber and function, information hidding/data hidding
advtange: data hide provide security,if we want ,we can make class only read only,code resuability
*/

#include<bits/stdc++.h>

using namespace std;

class student{
    private:
    string nanme;
    int roll;
    public:
    int getroll(){
        return this->roll;
    }
};

int main(){
    student first;
    cout<<"Sab Sahii Chal Raha Haii"<<endl;
    return 0;
}