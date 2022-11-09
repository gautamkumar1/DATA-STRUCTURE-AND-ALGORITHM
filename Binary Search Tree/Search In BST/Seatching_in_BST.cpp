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

Node*insertIntoBST(Node*root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else
    {
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void TakingInput(Node*&root){
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// Iterative Approach : T(n) : O(N)
bool isPresent(Node*root,int val){
    while (root!=NULL)
    {
        if(root->data == val){
            return 1;
        }
        // Searching value  in left side
        if(root->data > val){
            root = root->left;
        }
        // searching value in right side
        else
        {
            root = root->right;
        }
    }
    return 0;
}
// Recursive Approach : T(n): O(N)
bool IsFound(Node*root,int value){
    if(root==NULL){
        return 0;
    }
    if(root->data == value){
        return 1;
    }
    else if(root->data > value){
        return IsFound(root->left,value);
    }
    else
    {
        return IsFound(root->right,value);
    }
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    int Value = 60;
    if(IsFound(root,Value)){
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}