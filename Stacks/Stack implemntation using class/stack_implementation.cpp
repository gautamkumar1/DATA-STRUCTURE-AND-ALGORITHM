#include<iostream>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int*arr;
    // Creating a constructor
    Stack(int size){
        this->size =size;
        arr = new int[size];
        top = -1;
    }
    // Craeting a empty function
    bool isEmpty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
    // Craeting a isFull function
    bool isFull(){
        if(top==size-1){
            return 1;
        }
        return 0;
    }
    // Creating a push function
    void push(int data){
        if(isFull()){
            cout<<"Stack is overflow"<<endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    // creating a pop function
    int pop(){
        int val = -1;
        if(isEmpty()){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
        else
        {
            val = arr[top];
            top--;
            return val;
        }
        
    }
    // Creating peek / top function
    int peek(){
        return arr[top];
    }
    // creating a size function
    int length(){
        return size;
    }
};


int main(){
    Stack st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(48);
    cout<<"Size of stack is "<<st.length()<<endl;
    cout<<"Top element is "<<st.peek()<<endl;
    cout<<"Popped Element is "<<st.pop()<<endl;
    cout<<"Stack is Empty ? "<<st.isEmpty()<<endl;
    cout<<"Stack is full ? "<<st.isEmpty()<<endl;
}
