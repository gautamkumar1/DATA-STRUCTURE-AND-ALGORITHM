/*
Example 1 : 
Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.
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

// Approach 1 using Preorder Traversal
void preorder(Node *root, int node,int k,int &ans,vector<int> path){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    preorder(root->left,node,k,ans,path);
    preorder(root->right,node,k,ans,path);
    int len = path.size();
    for(int i = len-1; i>=0; i--){
        if(path[i]==node){
            if(i - k >= 0){
                ans = path[i-k];
                return ;
            }
        }
    }
    
}
int kthAncestor_usingApproach1(Node *root, int k, int node)
{
    
    vector<int> path;
    int ans = -1;
    preorder(root,node,k,ans,path);
    return ans;
}

// Approach 2
Node*solve(Node *root, int &k, int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node*leftAns = solve(root->left,k,node);
    Node*rightAns = solve(root->right,k,node);
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    
    Node*ans = solve(root,k,node);
    if(ans==NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;
    }
}
int main(){
    Node*root = NULL;
    root = BullidTree(root);
    cout<<"Enter the value of node to find : "<<endl;
    int node;
    cin>>node;
    cout<<"Enter the value of K for find KTh Anscestor : "<<endl;
    int k;
    cin>>k;
    int ans = kthAncestor_usingApproach1(root,k,node);
    cout<<"Approach  1  "<<endl;
    cout<<"KTh Anscestor of Node "<<node<<" is "<<ans<<endl;
    int ans2 = kthAncestor(root,k,node);
    cout<<"Approach  2  "<<endl;
    cout<<"KTh Anscestor of Node "<<node<<" is "<<ans2<<endl;
    return 0;
}