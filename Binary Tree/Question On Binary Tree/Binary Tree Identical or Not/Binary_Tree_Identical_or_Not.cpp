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
    if (data==-1)
    {
        return nullptr;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}

bool isIdentical(Node*r1,Node*r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1!=NULL && r2!=NULL){
        bool a = isIdentical(r1->left,r2->left);
        bool b = isIdentical(r1->right,r2->right);
        if ((r1->data == r2->data) && a && b)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    return false;
}

void preorder(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    cout<<"First Binary Tree Creation"<<endl;
    Node *root1 = NULL;
    root1 = BullidTree(root1);
    cout<<"Second Binary Tree Creation"<<endl;
    Node *root2 = NULL;
    root2 = BullidTree(root2);
    cout<<"\nFirst Binary Tree Element Are : "<<endl;
    preorder(root1);
    cout<<"\nSecond Binary Tree Element Are : "<<endl;
    preorder(root2);
    if(isIdentical(root1,root2)){
        cout<<"\nYes,Binary Tree Is Identical"<<endl;
    }
    else
    {
        cout<<"\nNo,Binary Tree Is Not Identical"<<endl;
    }
    return 0;
}