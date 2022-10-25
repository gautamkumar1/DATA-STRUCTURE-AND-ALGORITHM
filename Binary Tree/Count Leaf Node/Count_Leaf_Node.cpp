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
void solve(node *root, int &cnt)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    solve(root->left, cnt);
    solve(root->right, cnt);
}
int countLeafNode(node *root)
{
    int cnt = 0;
    solve(root, cnt);
    return cnt;
}
int main()
{
    node *root = NULL;
    root = bullidTree(root);
    int ans = countLeafNode(root);
    cout << "Total Number of leaf Node is " << ans << endl;
    return 0;
}