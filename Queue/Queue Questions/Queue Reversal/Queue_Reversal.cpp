#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// Using Stack and queue
queue<int> rev(queue<int> q)
{
    stack<int> st;
    queue<int> ans;
    // Step 1 : Push All Element in stack
    while(!q.empty()){ 
        st.push(q.front());
        q.pop();
    }
    // Step 2 : Push all stack data in queue
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    return ans;
    
}
void Display(queue<int> q){
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
}
int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    cout<<"Original Queue "<<endl;
    Display(q);
    queue<int> ans = rev(q);
    cout<<"Reversal Queue "<<endl;
    Display(ans);
    return 0;

}