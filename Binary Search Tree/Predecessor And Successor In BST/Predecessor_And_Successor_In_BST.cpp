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
// Predecessor And Successor In BST
pair<int,int>PredecessorAndSuccessorInBST(Node*root,int key){
    // Predecessor -> leftsubtree ka maximum element hoga
    // Successor -> RightSubtree ka minimum element hoga
    int pred = -1;
    int succ = -1;
    Node*current = root;
    // Finding Key
    while(current->data!=key){
        if(current->data > key){
            // Storeing successor
            succ = current->data;
            current = current->left;
        }
        else
        {
            // Storeing predecessor
            pred = current->data;
            current = current->right;
        }
        
    }
    // Finding predecessor
    Node*leftSubTree = current->left;
    while (leftSubTree!=NULL)
    {
        pred = leftSubTree->data;
        leftSubTree = leftSubTree->right;
    }
    // Finding successor
    Node*rightSubTree = current->right;
    while (rightSubTree!=NULL)
    {
        succ = rightSubTree->data;
        rightSubTree = rightSubTree->left;
    }
    return {pred,succ};
}
int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    int key;
    cout<<"Enter the key : "<<endl;
    cin>>key;
    pair<int,int> p = PredecessorAndSuccessorInBST(root,key);
    cout<<"Predecessor and Successor of "<<key<<" is : "<<p.first<<" and "<<p.second<<endl;
    return 0;
}