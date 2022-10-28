#include<iostream>
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
    cout<<"Enter the data for inserting in Left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data for inserting in Right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}

int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    int len = height(root);
    cout<<"Height of Binary Tree is "<<len<<endl;
    return 0;
}