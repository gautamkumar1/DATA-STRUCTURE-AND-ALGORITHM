#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int row;
    int col;
    node(int data, int i, int j)
    {
        this->data = data;
        row = i;
        col = j;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
// T(n) : O(K*Log(K)) and S(N) : O(K)
vector<int> mergeKArrays(vector<vector<int>> kArrays, int k)
{
    // code here
    priority_queue<node *, vector<node *>, compare> minHeap;
    //  Step 1 : karrays ke saare element heap me daal do
    for (int i = 0; i < k; i++)
    {
        node *tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }
    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        int i = tmp->row;
        int j = tmp->col;
        if (j + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main(){
    int k = 3;
    vector<vector<int>> kArrays = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
    };
    vector<int>ans = mergeKArrays(kArrays,k);
    cout<<"K Merge Array are "<<endl;
    for(auto val:ans){
        cout<<val<<" ";
    }
    return ans;
}