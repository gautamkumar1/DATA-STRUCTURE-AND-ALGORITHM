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

Node *BullidTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data from inserting left of " << data << endl;
    root->left = BullidTree(root->left);
    cout << "Enter the data from inserting right of " << data << endl;
    root->right = BullidTree(root->right);
    return root;
}

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    return ans;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    int ans = getMaxSum(root);
    cout<<"The maximum sum is sum of node is "<<ans<<endl;
    return 0;
}