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

Node*insertTonode(Node*root,int value){
    if(root==NULL){
        root = new Node(value);
        return root;
    }
    if(root->data > value){
        root->left = insertTonode(root->left,value);
        
    }
    else
    {
        root->right = insertTonode(root->right,value);
    }
    return root;
}

void taking_input(Node*&root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root = insertTonode(root,data);
        cin>>data;
    }
    
}
// Check Tree BST or not
bool solution(Node*&root,int min,int max){
    // Base Case
    if(root==NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = solution(root->left,min,root->data);
        bool right = solution(root->right,root->data,max);
        return left&&right;
    }
    else
    {
        return false;
    }
}
// bool isBST(Node*root){
//     return solution(root,INT_MIN,INT_MAX);
// }
int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    taking_input(root);
    return 0;
}