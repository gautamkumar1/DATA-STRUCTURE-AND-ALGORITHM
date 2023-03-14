/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
// T(n) : o(n) and S(n) : O(h) / o(n)
int isSum(TreeNode* root, int currsum) {
    if (root == NULL) {
        return 0;
    }
    currsum = currsum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return currsum;
    }
    int left = isSum(root->left,currsum);
    int right = isSum(root->right,currsum);
    return left+right;
}

int sumNumbers(TreeNode* root) {
    int currSum = 0;
    return isSum(root,currSum);
}

int main() {
    // create the binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    // calculate the sum of all root-to-leaf paths
    int sum = sumNumbers(root);

    // output the sum
    cout << "The sum of all root-to-leaf paths is: " << sum << endl;

    return 0;
}
