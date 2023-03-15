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

int Get_height(node*root){
    return root==NULL ? 0 : max(Get_height(root->left),Get_height(root->right))+1;
}
// T(n) : O(n^2)
bool isBalanced(node*root){
    if(root==NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(Get_height(root->left)-Get_height(root->right))<=1;
    if(left && right && diff){
        return true;
    }
    else
    {
        return false;
    }
}
// Optimize Solution : T(n) -> O(n)  and s(n) : O(n)
int height(node*root){
    if(root == NULL) return 0;
    int left = height(root->left);
    if(left == -1) return -1;
    int right = height(root->right);
    if(right == -1) return -1;
    if( abs(left - right) > 1) return -1;
    return max(left,right)+1;
}
bool isBalancedBT(node* root) {
   if(root==NULL) return true;
   return height(root) != -1;
}
int main(){
    node*root = NULL;
    root = bullidTree(root);
    if(isBalancedBT(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else
    {
        cout<<"Not Balanced Tree"<<endl;
    }
    return 0;
}