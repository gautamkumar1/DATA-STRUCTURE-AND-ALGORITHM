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

void ReverseLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<int> st;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        st.push(temp->data);
        q.pop();
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = BUllidTree(root);
    ReverseLevelOrder(root);
    return 0;
}