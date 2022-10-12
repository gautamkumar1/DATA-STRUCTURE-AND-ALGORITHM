#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> insertAtBottom(stack<int>&s,int x){
    solve(s,x);
    return s;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> ans = insertAtBottom(st,5);;
    while (!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}