#include<iostream>
using namespace std;
class Queue{
    int size;
    int front;
    int rear;
    int*arr;
    public:
    Queue(int size){
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[size];
    }
    bool isEmpty(){
        if (front == rear)
        {
            return 1;
        }
        return 0;
    }
    bool isFull(){
        if(rear == size-1){
            return 1;
        }
        return 0;
    }
    void Enqueue(int data){
        if(isFull()){
            cout<<"Sorry We Cannot Push "<<data<<" in queue bcz Queue is Overflow"<<endl;
            return ;
        }
        arr[++rear] = data;
        cout<<data<<" is Successfull Enqueue in Queue"<<endl;
    }
    int Dequeue(){
        if(isEmpty()){
            cout<<"Queue is Underflow "<<endl;
            return -1;
        }
        front++;
        int val = arr[front];
        return val;
    }
};

int main(){
    Queue*q = new Queue(5);
    q->Enqueue(1);
    q->Enqueue(2);
    q->Enqueue(3);
    q->Enqueue(4);
    q->Enqueue(5);
    cout<<"Dequeue Element is "<<q->Dequeue()<<endl;
    cout<<"Queue Is Full Or Not "<<q->isFull()<<endl;
    cout<<"Queue Is Empty Or Not "<<q->isEmpty()<<endl;
    return 0;
}