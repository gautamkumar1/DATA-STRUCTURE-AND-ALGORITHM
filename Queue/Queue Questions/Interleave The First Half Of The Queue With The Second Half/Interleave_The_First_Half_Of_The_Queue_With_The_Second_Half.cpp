/*
iven a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.  
Note : Length of queue is always even
Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/

#include<bits/stdc++.h>
using namespace std;

queue<int> interLeaveQueue(queue < int > & q) {
    int len = q.size();
    // Step 1 Create a new queue and put size/2 tak value in old queue
    queue<int> newQueue;
    int mid = len/2;
    int count = 1;
    while(!q.empty() && count<=mid){
        newQueue.push(q.front());
        q.pop();
        count++;
    }
    // Step2 : pop front of newqueue and push in old queue or pop front in old queue and push again in old queue
    while(!newQueue.empty()){
        int val = newQueue.front();
        q.push(val);
        newQueue.pop();
        int val2 = q.front();
        q.push(val2);
        q.pop();
    }
    return q;
}
void Display(queue<int> q){
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
    cout<<"Before interleave first half of the quueu: "<<endl;
    Display(q);
    queue<int> ans = interLeaveQueue(q);
    cout<<"After interleave first half of the quueu: "<<endl;
    Display(ans);
    return 0;
}