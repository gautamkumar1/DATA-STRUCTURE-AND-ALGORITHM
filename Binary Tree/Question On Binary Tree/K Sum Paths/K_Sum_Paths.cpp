/*
Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
*/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*BullidTree(Node*root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data from inserting left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data from inserting right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}
void solve(Node *root,int k,int&cnt,vector<int> path){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    solve(root->left,k,cnt,path);
    solve(root->right,k,cnt,path);
    int sum =0;
    for(int i = path.size()-1; i>=0; i--){
        sum+=path[i];
        if(sum==k){
            cnt++;
        }
    }
    path.pop_back();
}
int sumK(Node *root,int k){
    if(root==NULL){
        return -1;
    }
    int cnt = 0;
    vector<int> path;
    solve(root,k,cnt,path);
    return cnt;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    cout<<"Enter the K sum path : "<<endl;
    int k;
    cin>>k;
    int ans = sumK(root,k);
    cout<<"Total k Sum Path is "<<ans<<endl;
    return ans;
}