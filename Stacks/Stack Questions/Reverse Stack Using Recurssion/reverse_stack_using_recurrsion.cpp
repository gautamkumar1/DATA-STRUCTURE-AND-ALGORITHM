#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> st,int num){
    if(st.empty()){
        st.push(num);
        return ;
    }
    int ele = st.top();
    st.pop();
    insertAtBottom(st,num);
    st.push(ele);
}

void reverse_Stack(stack<int> st){
    if(st.empty()){
        return ;
    }
    int ele = st.top();
    st.pop();
    reverse_Stack(st);
    insertAtBottom(st,ele);
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
    cout<<"Reverse Stack is "<<endl;
    reverse_Stack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}