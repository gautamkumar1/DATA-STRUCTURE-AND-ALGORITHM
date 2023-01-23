#include<iostream>
#include<vector>
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
void display(Node*root){
    if(root==NULL)
        return ;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
void inorder(Node* root,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
Node* flatten(Node* root)
{
    vector<int>arr;
    inorder(root,arr);
    int n = arr.size();
    Node* newRoot = new Node(arr[0]);
    Node* current = newRoot;
    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i]);
        current->left = NULL;
        current->right = temp;
        current = temp;
    }
    current->left = NULL;
    current->right = NULL;
    return newRoot;
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    Node*ans = flatten(root);
    cout<<"Sorted List "<<endl;
    display(ans);
    return 0;
}
