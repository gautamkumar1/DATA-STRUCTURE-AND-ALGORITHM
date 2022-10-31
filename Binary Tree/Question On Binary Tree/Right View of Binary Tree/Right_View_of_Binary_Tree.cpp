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
    if (data==-1)
    {
        return nullptr;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}
void solve(Node*root,vector<int>&ans,int level){
    if(root==NULL){
        return ;
    }
    // We entred in new level
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}
vector<int> RightView(Node*root){
    int level = 0;
    vector<int> ans;
    solve(root,ans,level);
    return ans;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    vector<int> ans = RightView(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}