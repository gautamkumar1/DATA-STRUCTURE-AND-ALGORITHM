#include<bits/stdc++.h>
using namespace std;
//static me object krne ki need nhi hai , agr aap chahe to kr skte hai wrna uska need nhi hai
// static keyword ko abject ke bahar hi krna pdta hai declare , or hum object ke andar bhi kr skte hai
// syntax-> data_type class_name :: static_variable_name = value
class student{
    public:
    static int id;
};

int student :: id = 441; // yah accha practice hai
int main(){
    cout<<student::id<<endl;
    student gautam;
    cout<<gautam.id<<endl;
    gautam.id = 44; // yah bad practice hai
    cout<<gautam.id<<endl;
    cout<<student::id<<endl;
    return 0;
}
