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
Node* inorderToBST(vector<int>&arr,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    root->left = inorderToBST(arr,start,mid-1);
    root->right = inorderToBST(arr,mid+1,end);
    return root;
}
Node* balancedBst(Node* root) {
    vector<int>arr;
    inorder(root,arr);
    int start = 0;
    int end = arr.size()-1;
    return inorderToBST(arr,start,end);
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    cout<<"Given BST "<<endl;
    display(root);
    Node*ans = balancedBst(root);
    cout<<"Balanced BST"<<endl;
    display(ans);
    return 0;
}