#include<bits/stdc++.h>
// create custom data structre
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int r,int c){
        this->data = data;
        row = r;
        col = c;
    }
};
// create compare to find element

class compare{
    public:
    bool operator() (node*a,node*b){
        return a->data > b->data;
    }
}

pair<int,int> findSmallestRange(vector<int<vector<int>>&arr, int n, int k){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    priority_queue<node*,vector<node*> compare> minheap;
    // k arrays ke fisrt element me se max and min element nikal rahe hai
    for(int i=0; i<k; i++){
        int element = arr[i][0];
        maxi = max(maxi,element);
        mini = min(mini,element);
        node*temp = new node(element,i,0);
        minheap.push(temp);
    }
    int start = mini;
    int end = maxi;
    while(!minheap.empty()){
        node*top = minheap.top();
        minheap.pop();
        mini = top->data;
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        int row = top->row;
        int col = top->col;
        if(col+1 < n){
            maxi = max(maxi,arr[row][col+1]);
            node*next = new node(arr[row][col+1],row,col+1);
            minheap.push(next);
        }
        else{
            break;
        }
    }
    return {start,end};
}

int main(){
    vector<int<vector<int>> arr = {{1 ,3 ,5 ,7 ,9},
                    {0 ,2, 4 ,6 ,8},
                    {2 ,3 ,5, 7 ,11}
                    };
    int n = arr[][0].size();
    int k = 3;
    pair<int,int> ans = findSmallestRange(arr,n,k);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
    
}