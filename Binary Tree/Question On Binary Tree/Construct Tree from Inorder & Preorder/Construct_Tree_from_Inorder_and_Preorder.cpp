#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int GetPostition(int in[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
Node *constructTree(int in[], int pre[], int n, int &PreorderStartIndex, int InorderStartIndex, int IndorderEndIndex)
{
    // Base Case
    if (PreorderStartIndex >=n || InorderStartIndex > IndorderEndIndex)
    {
        return NULL;
    }
    int element = pre[PreorderStartIndex++];
    // Createing root Node
    Node *root = new Node(element);
    // Finding Postion of root element in Inorder array
    int position = GetPostition(in, n, element);
    // Recursive Calls
    root->left = constructTree(in,pre, n, PreorderStartIndex, InorderStartIndex, position - 1);
    root->right = constructTree(in,pre, n, PreorderStartIndex, position + 1, IndorderEndIndex);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int PreorderStartIndex = 0;
    int InorderStartIndex = 0;
    int IndorderEndIndex = n - 1;
    Node *ans = constructTree(in,pre, n, PreorderStartIndex, InorderStartIndex, IndorderEndIndex);
    return ans;
}
void PostorderTraversal(Node*root){
    if(root==NULL){
        return ;
    }
    PostorderTraversal(root->left);
    cout<<root->data<<" ";
    PostorderTraversal(root->right);
}
int main(){
    int inorder[] = {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
    int preorder[] = {8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
    int n = 8;
    Node*root = buildTree(inorder,preorder,n);
    PostorderTraversal(root);
    return 0;
}