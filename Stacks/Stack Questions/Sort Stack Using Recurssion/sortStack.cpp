#include<iostream>
#include<stack>
using namespace std;
void sortedInsert(stack<int> st,int num){
    if(st.empty() || (!st.empty() && st.top()<=num)){
        st.push(num);
        return ;
    }
    int ele = st.top();
    st.pop();
    sortedInsert(st,num);
    st.push(ele);
}

void Sort_Stack(stack<int> s){
    if(s.empty()){
        return ;
    }
    int num = s.top();
    s.pop();
    Sort_Stack(s);
    sortedInsert(s,num);
}

int main(){
    cout<<"Enter the size of stack: "<<endl;
    int size;
    cin>>size;
    stack<int> st;
    for(int i = 0; i<size; i++){
        cout<<"Enter the value in stack : "<<endl;
        int val;
        cin>>val;
        st.push(val);
    }
    cout<<"Sorted Stack is "<<endl;
    Sort_Stack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}