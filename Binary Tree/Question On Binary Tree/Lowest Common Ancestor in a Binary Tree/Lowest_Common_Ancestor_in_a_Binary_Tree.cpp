/*
LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
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

Node* lca(Node* root ,int n1 ,int n2 ){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node*leftAns = lca(root->left,n1,n2);
    Node*rightAns = lca(root->right,n1,n2);
    if(leftAns!=NULL && right!=NULL){
        return root;
    }
    else if(leftAns!=NULL && right==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && right!=NULL){
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    cout<<"Enter the value of N1 : "<<endl;
    int n1;
    cin>>n1;
    cout<<"Enter the value of N2 : "<<endl;
    int n2;
    cin>>n2;
    Node*ans = lca(root,n1,n2);
    cout<<"LCA of "<<n1<<" and "<<n2<<" is : "<<ans->data<<endl;
    return 0;
}