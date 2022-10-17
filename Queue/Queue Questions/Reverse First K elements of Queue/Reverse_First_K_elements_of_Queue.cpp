/*
Example 1:

Input:
N = 5 , K = 3
Queue = 1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5
*/
#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    int i = 1;
    while(!q.empty() && i<=k){
        st.push(q.front());
        q.pop();
        i++;
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    int remainingPart = q.size()-k;
    while(remainingPart--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

void display(queue<int> q){
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    cout<<"Before Modification queue "<<endl;
    display(q);
    queue<int> ans = modifyQueue(q,k);
    cout<<"After Modification queue "<<endl;
    display(ans);
    return 0;
}