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
Node *constructTree(int in[], int post[], int n, int &PostorderLastIndex, int InorderStartIndex, int IndorderEndIndex)
{
    // Base Case
    if (PostorderLastIndex < 0 || InorderStartIndex > IndorderEndIndex)
    {
        return NULL;
    }
    int element = post[PostorderLastIndex--];
    // Createing root Node
    Node *root = new Node(element);
    // Finding Postion of root element in Inorder array
    int position = GetPostition(in, n, element);
    // Recursive Calls
    root->right = constructTree(in, post, n, PostorderLastIndex, position + 1, IndorderEndIndex);
    root->left = constructTree(in, post, n, PostorderLastIndex, InorderStartIndex, position - 1);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int PostorderLastIndex = n - 1;
    int InorderStartIndex = 0;
    int IndorderEndIndex = n - 1;
    Node *ans = constructTree(in, post, n, PostorderLastIndex, InorderStartIndex, IndorderEndIndex);
    return ans;
}

int main(){
    int inorder[] = {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
    int postorder[] = {8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
    int n = 8;
    Node*root = buildTree(inorder,postorder,n);
    PreorderTraversal(root);
    return 0;
}