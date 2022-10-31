#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *bullidTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = bullidTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = bullidTree(root->right);
    return root;
}

int height(node*root){
    return root==NULL ? 0 : max(height(root->left),height(root->right))+1;
}
bool isBalanced(node*root){
    if(root==NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff){
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    node*root = NULL;
    root = bullidTree(root);
    if(isBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else
    {
        cout<<"Not Balanced Tree"<<endl;
    }
    return 0;
}