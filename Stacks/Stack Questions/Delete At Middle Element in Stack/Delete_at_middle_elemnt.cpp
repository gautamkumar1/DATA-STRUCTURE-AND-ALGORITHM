#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&inputStack, int cnt,int size){
    // Base case
    if(cnt == size/2){
        inputStack.pop();
        return ;
    }
    // Storeing top value
    int num = inputStack.top();
    inputStack.pop();
    // Recursive Call;
    solve(inputStack,cnt+1,size);
    // BackTracking
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
    int cnt = 0;
    solve(inputStack,cnt,N);
   
}
int main(){
    cout<<"Enter the size of stack "<<endl;
    int size;
    cin>>size;
    stack<int> inputStack;
    for ( int i = 0; i < size; i++)
    {
        cout<<"Enter the value in stack : "<<endl;
        int val;
        cin>>val;
        inputStack.push(val);
    }
    deleteMiddle(inputStack,size);
    cout<<"After Delete Middle Element In Stack "<<endl;
    while (!inputStack.empty())
    {
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
    return 0;
}