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

// Kth Smallest Element
// T(N) : O(N) and S(N) : O(N)
int solve(Node*root,int&i,int k){
    // Solve using inorder traversal 
    if(root==NULL){
        return -1;
    }
    // Left Part
    int left = solve(root->left,i,k);

    if(left!=-1){
        return left;
    }
    // Increment i
    i++;
    // Checking i == K 
    if(i==k){
        return root->data;
    }

    // else return right part
    return solve(root->right,i,k);
}
int kthSmallestElement(Node*root,int k){
    int i=0;
    return solve(root,i,k);
}
int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    int ans = kthSmallestElement(root,2);
    cout<<"Kth Smallest Element is : "<<ans<<endl;
    return 0;
}