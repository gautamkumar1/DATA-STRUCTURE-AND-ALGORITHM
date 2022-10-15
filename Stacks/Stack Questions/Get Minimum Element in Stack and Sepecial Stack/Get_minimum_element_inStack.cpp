#include<iostream>
#include<stack>
using namespace std;

class SpecialStack{
    stack<int> st;
    int mini;
    public:
    void push(int data){
        if (st.empty())
        {
            st.push(data);
            mini = data;
        }
        else
        {
            if(data<mini){
                int value = 2*data-mini;
                st.push(value);
                mini = data;
            }
            else
            {
                st.push(data);
            }
            
        }
    }
    int pop(){
        if(st.empty()){
            return -1;
        }
        int current = st.top();
        st.pop();
        if(current>mini){
            return current;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini-current;
            mini = val;
            return prevMin;
        }
        
    }
    bool isEmpty(){
        return st.empty();
    }
    int top(){
        if(st.empty()){
            return -1;
        }
        int current = st.top();
        if(current<mini){
            return current;
        }
        else
        {
            return mini;
        }
    }
    int getMinimum(){
        if(st.empty()){
            return -1;
        }
        return mini;
    }
};

int main(){
    SpecialStack st;
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(3);
    cout<<"Top Element is : "<<st.top()<<endl;
    cout<<"Popped Element is : "<<st.pop()<<endl;
    cout<<"Minimum Element is : "<<st.getMinimum()<<endl;
    return 0;
}