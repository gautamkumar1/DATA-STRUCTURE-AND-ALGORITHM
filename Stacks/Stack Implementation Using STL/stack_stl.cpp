#include<bits/stdc++.h>
using namespace std;
/*
  
The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
*/
int main(){
    // Suntax for creating stack : stack<datatye> variable_name
    stack<int> s;
    // insertion in stack suing push function
    s.push(1); 
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5); // --> This element is called top of the stack / peekmof the stack
    cout<<"Before pop function using top / peek element is "<<s.top()<<endl;
    // deletion in stack using pop function
    s.pop();
    cout<<"After pop function using Top / peek element is "<<s.top()<<endl;
    // finding stack size using size function
    cout<<"Size of stack is "<<s.size()<<endl;
    // Checking stack is empty or not , It always return boolean value
    cout<<s.empty()<<endl;
    return 0;
}