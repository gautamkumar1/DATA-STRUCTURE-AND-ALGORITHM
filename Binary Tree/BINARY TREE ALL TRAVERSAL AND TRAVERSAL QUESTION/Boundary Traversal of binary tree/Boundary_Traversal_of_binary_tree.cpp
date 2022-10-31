#include <iostream>
#include <vector>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *bullidTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter the data for inserting in left of : " << data << endl;
    root->left = bullidTree(root->left);
    cout << "Enter the data for inserting in right of : " << data << endl;
    root->right = bullidTree(root->right);
    return root;
}
void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left != nullptr)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeafNOde(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
    }
    traverseLeafNOde(root->left, ans);
    traverseLeafNOde(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right != NULL)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> BoundaryLevelTraversal(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    ans.push_back(root->data);
    // Step 1: TraverseLeft without leaf Node
    traverseLeft(root->left, ans);
    // Step 2 : Traverse Leaf Node
    // 1st : Left subtree
    // 2nd : right subtree
    traverseLeafNOde(root->left, ans);
    traverseLeafNOde(root->right, ans);
    // Step 3 : Traverse Reverse Right
    traverseRight(root->right, ans);
    return ans;
}

int main(){
    Node*root = NULL;
    root = bullidTree(root);
    vector<int> ans = BoundaryLevelTraversal(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}