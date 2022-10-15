#include<iostream>
using namespace std;
class NStack{
    int*arr;
    int*top;
    int*next;
    int size,n,freeSpot;
    public:
    NStack(int size,int n){
        this->size = size;
        this->n = n;
        arr = new int[size];
        top = new int[n];
        next = new int[size];
        freeSpot = 0;
        // Initialize Top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // Initialize Next
        for (int i = 0; i < size; i++)
        {
            next[i] = i+1;
        }
        // Update last element in next with -1
        next[size-1] = -1;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x,int n){
        // Overflow Condition
        if(freeSpot==-1){
            return false;
        }
        // Finding Index
        int index = freeSpot;
        // Update freespot
        freeSpot = next[index];
        // Insert element into array
        arr[index] = x;
        // Update next
        next[index] = top[n-1];
        // Update top
        top[n-1] = index;
        return true;
    }
    // Pop Ke value jo jo push me likhe sabko reverse krke likh dena hai niche se bas insert element wala chorke last return arr[index] krna hai 
    int pop(int n){
        // Underflow Condition
        if(top[n-1]==-1){
            return -1;
        }
        int index = top[n-1];
        top[n-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main(){
    NStack*st = new NStack(6,3);
     if(st->push(85,1)){
        cout<<"Entred Value in Stack 1"<<endl;
    }
    else
    {
        cout<<" Not Entred Value in Stack 1"<<endl;
    }
     if(st->push(125,2)){
        cout<<"Entred Value in Stack 2"<<endl;
    }
    else
    {
        cout<<"Not Entred Value in Stack 2"<<endl;
    }
     if(st->push(965,3)){
        cout<<"Entred Value in Stack 3"<<endl;
    }
    else
    {
        cout<<" Not Entred Value in Stack 3"<<endl;
    }
    cout<<"Popped Element in stack 1 "<<st->pop(1)<<endl;
    cout<<"Popped Element in stack 2 "<<st->pop(2)<<endl;
    cout<<"Popped Element in stack 3 "<<st->pop(3)<<endl;
    return 0;   
}