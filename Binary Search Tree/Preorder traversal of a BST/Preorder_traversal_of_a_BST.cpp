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

Node* solve(vector<int> &preorder,int mini,int maxi,int&i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    Node*root = new Node(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}
Node* preorderToBST(vector<int> &preorder) {
    int i=0;
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return solve(preorder,mini,maxi,i);
}

int main(){
    vector<int> preorder = {10 ,4 ,3 ,7 ,40 ,55 };
    Node*ans = preorderToBST(preorder);
    display(ans);
    return 0;
}

