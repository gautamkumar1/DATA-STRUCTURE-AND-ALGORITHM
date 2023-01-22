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

Node*insertNodeInBST(Node*root,int value){
    if(root==NULL){
        root = new Node(value);
        return root;
    }
    // Inserting Node in right side
    if(value > root->data){
        
        root->right = insertNodeInBST(root->right,value);
    }
    // Inserting Node in left side
    else
    {
        root->left = insertNodeInBST(root->left,value);
    }
    return root;
}

void TakingInput(Node*&root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root = insertNodeInBST(root,data);
        cin>>data;
    }
}
Node*LCA(Node*root,Node*key1,Node*key2){
    if(root==NULL){
        return NULL;
    }
    // Case 1
    if(root->data > key1->data && root->data > key2->data){
        return LCA(root->left,key1,key2);
    }
    // Case 2
    if(root->data < key1->data && root->data < key2->data){
        return LCA(root->right,key1,key2);
    }
    // Case 3 and Case 4
    return root;
}
int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    return 0;
}