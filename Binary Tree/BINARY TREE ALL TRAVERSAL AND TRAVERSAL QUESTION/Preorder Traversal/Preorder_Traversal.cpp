#include <bits/stdc++.h>
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

Node *BUllidTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data from inserting in left of " << data << endl;
    root->left = BUllidTree(root->left);
    cout << "Enter the data from inserting in rightt of " << data << endl;
    root->right = BUllidTree(root->right);
    return root;
}

void Preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = BUllidTree(root);
    Preorder(root);
    return 0;
}