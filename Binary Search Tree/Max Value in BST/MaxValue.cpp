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

void Inorder(Node*&root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
Node*GetMax(Node*root){
    Node*current = root;
    // Max value always right side me milega
    while (current->right!=NULL)
    {
        current = current->right;
    }
    return current;
}
int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    cout<<"Inorder Traversal Of BST Is : "<<endl;
    Inorder(root);
    cout<<"\nMaximum Value In BST is "<<GetMax(root)->data<<endl;
    return 0;
}

