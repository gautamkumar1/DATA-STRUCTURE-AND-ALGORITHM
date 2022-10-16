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
        else
        {
            return 0;
        }
    }
    // Craeting a isFull function
    bool isFull(){
        if(top==size-1){
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    // Creating a push function
    void push(int data){
        if(isFull()){
            cout<<"Sorry we cannot push "<<data<<" because stack is overflow"<<endl;
        }
        else
        {
            
            top++;
            arr[top] = data;
            cout<<data<<" is Push SucessFull in Stack"<<endl;
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
        if(isEmpty()){
            return -1;
        }
        return arr[top];
    }
    // creating a size function
    int length(){
        return size;
    }
    // Stack bottom function create
    int BottomElement(){
        if(isEmpty()){
            return -1;
        }
        return arr[size-1];
    }
    // Stack TopValue Function create
    int TopElement(){
       if(isEmpty()){
            return -1;
        }
        return arr[0]; 
    }
};


int main(){
    Stack st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(48);
    st.push(478);
    cout<<"Size of stack is "<<st.length()<<endl;
    cout<<"Top element is "<<st.peek()<<endl;
    cout<<"Stack is Empty ? "<<st.isEmpty()<<endl;
    cout<<"Stack is full ? "<<st.isFull()<<endl;
    cout<<"Stack Top Value is "<<st.TopElement()<<endl;
    cout<<"Stack Bottom Value is "<<st.BottomElement()<<endl;
    cout<<"Popped Element is "<<st.pop()<<endl;
    return 0;
}
