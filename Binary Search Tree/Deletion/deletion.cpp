#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node*NodetoInsert(node*root,int val){
    if(root==NULL){
        root = new node(val);
        return root;
    }
    if(root->data > val){
        root->left = NodetoInsert(root->left,val);
    }
    else
    {
        root->right = NodetoInsert(root->right,val);
    }
    return root;
}

void taking_input(node*&root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root = NodetoInsert(root,data);
        cin>>data;
    }
}
// Inorder Traversal
void inorder(node*root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Get Minimum Value
node*GetMin(node*root){
    node*current = root;
    // Min value always left side me milega
    while (current->left!=NULL)
    {
        current = current->left;
    }
    return current;
}
// Deletion
// Time Complexity : O(H) or O(N)
node*deleteToNode(node*root,int value){
    // Base Case
    if(root==NULL){
        return NULL;
    }
    if(root->data == value){
        // Leaf Node 
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 Child
        // Left Part
        if(root->left!=NULL && root->right==NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        // Right Part
        if(root->left==NULL && root->right!=NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            // Find Minimum Value in right side
            int minValue = GetMin(root->right)->data;
            root->data = minValue;
            root->right = deleteToNode(root->right,minValue);
            return root;
        }
    }
    else if(root->data > value){
        root->left = deleteToNode(root->left,value);
        return root;
    }
    else
    {
        root->right = deleteToNode(root->right,value);
        return root;
    }
    
}
int main(){
    node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    taking_input(root);
    cout<<"Inorder Traversal Of BST Is : ";
    inorder(root);
    root = deleteToNode(root,5);
    cout<<"Inorder Traversal Of BST Is : ";
    inorder(root);
    return 0;
}