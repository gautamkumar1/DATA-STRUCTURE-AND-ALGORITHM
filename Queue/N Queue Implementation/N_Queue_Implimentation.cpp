#include <bits/stdc++.h> 
using namespace std;
class NQueue{
    int size;
    int n;
    int freespot;
    int*front;
    int*rear;
    int*next;
    int*arr;
public:
    NQueue(int n, int s){
        this->n = n;
        this->size = s;
        front = new int[n];
        rear = new int[n];
        for(int i=0; i<n; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[s];
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
        arr = new int[s];
        freespot = 0;
    }
    bool enqueue(int x, int m){
        // Overflow Condition
        if(freespot==-1){
            return 0;
        }
        // Find index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // Wheteher one element push
        if(front[m-1]==-1){
            front[m-1] = index;
        }
        else{
            // Link new element to previous element
            next[rear[m-1]] = index;
        }
        // update next index
        next[index] = -1;
        // update rear index
        rear[m-1] = index;
        // Push element into array
        arr[index] = x;
        return 1;
    }
    int dequeue(int m){
        // underflow condition
        if(front[m-1]==-1){
            return -1;
        }
        // find index
        int index = front[m-1];
        // Increment front index
        front[m-1] = next[index];
        // Update free index
        next[index] = freespot;
        freespot = index;
        // Return Value
        return arr[index];
    }
};

int main(){
    NQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(45,2);
    q.enqueue(101,1);
    q.enqueue(1890,1);
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    return 0;
}