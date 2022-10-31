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

void solve(Node *root,map<int,vector<int> >&mp,int level){
    if(root==NULL){
        return ;
    }
    mp[level].push_back(root->data);
    solve(root->left,mp,level+1);
    solve(root->right,mp,level);
}
vector<int> diagonal(Node *root)
{
    map<int,vector<int> > mp;
    vector<int> ans;
    int level = 0;
    solve(root,mp,level);
    for(auto i : mp){
        for(auto j : i.second){
            ans.push_back(j);
        }
    }
    return ans;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    vector<int> ans = diagonal(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}
