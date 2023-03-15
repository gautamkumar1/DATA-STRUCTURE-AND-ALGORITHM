#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// T(N) : O(N) and S(N) : O(H) using DFS
int getlen(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + getlen(root->left) + getlen(root->right);
}
bool solution(TreeNode *root, int i, int n)
{
    if (root == NULL)
        return 1;
    if (i > n)
    {
        return 0;
    }
    bool left = solution(root->left, 2 * i, n);
    bool right = solution(root->right, 2 * i + 1, n);
    return (left && right);
}
bool isCompleteTree(TreeNode *root)
{
    int n = getlen(root);
    return solution(root, 1, n);
}

int main()
{
    // create the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // check if the binary tree is a complete tree
    bool isComplete = isCompleteTree(root);
    if (isComplete)
    {
        cout << "The binary tree is a complete tree." << endl;
    }
    else
    {
        cout << "The binary tree is not a complete tree." << endl;
    }

    return 0;
}
