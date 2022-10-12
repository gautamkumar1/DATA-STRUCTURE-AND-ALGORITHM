#include<iostream>
using namespace std;

class TwoStack{
    int size;
    int top1;
    int top2;
    int*arr;
    public:
    // stack one me left to right insertion deletion hoga or isme top = -1
    // stack two me right to left hoga , isme top = size hoga
    // Create push1 function if top2-top1>1 then insert in stack
    TwoStack(int size){
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        arr = new int[size];
    }
    void push1(int data){
        if(top2-top1>1){
            top1++;
            arr[top1] = data;
        }
    }
    int pop1(){
        if(top1>0){
            int val = arr[top1];
            top1--;
            return val;
        }
    }
    // creating two stack
    void push2(int data){
        if(top2-top1>1){
            top2--;
            arr[top2] = data;
        }
    }
    int pop2(){
        if(top2<size){
            int val = arr[top2];
            top2++;
            return val;
        }
    }
};

int main(){
    TwoStack st(4);
    st.push1(4);
    st.push1(454);
    st.push2(999855);
    st.push2(91);
    cout<<"Popped element is "<<st.pop1()<<endl;
    cout<<"Popped element is "<<st.pop2()<<endl;
    return 0;
}