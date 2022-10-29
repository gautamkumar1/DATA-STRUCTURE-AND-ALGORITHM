/*
Example 1:

Input:
    3
  /   \
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.
*/

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

Node *BullidTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = BullidTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = BullidTree(root->right);
    return root;
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 != NULL)
    {
        bool a = isIdentical(r1->left, r2->left);
        bool b = isIdentical(r1->right, r2->right);
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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int GetSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = GetSum(root->left) + GetSum(root->right) + root->data;
    return ans;
}

bool isSumTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int isleft = isSumTree(root->left);
    int isright = isSumTree(root->right);
    bool condition = GetSum(root->left) + GetSum(root->right) == root->data;
    if (isleft && isright && condition)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    cout<<"\nBinary Tree Element are : "<<endl;
    preorder(root);
    if(isSumTree(root)){
        cout<<"\nYes \n";
    }
    else
    {
        cout<<"\nNo \n";
    }
    
    return 0;
}