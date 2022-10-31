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
/*
ZigZag Tree Traversal means fisrt left to right and then right to left.
T(n) : O(N) and S(n) : O(N)
*/
vector<int> ZigZag_Traversal(Node*root){
    if(root==NULL){
        return {};
    }
    vector<int> result;
    bool leftToright = true;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        // Level Process
        for(int i=0; i<size; i++){
            Node*temp = q.front();
            q.pop();
            // Insert Value Normal and Reverse order
            int index = leftToright ? i : size - i - 1;
            ans[index] = temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        // Change Direction Now Left To right 
        leftToright = !leftToright;
        for(auto val : ans){
            result.push_back(val);
        }
    }
    return result;
}

int main(){
    Node*root = NULL;
    root  = BUllidTree(root);
    vector<int> ans = ZigZag_Traversal(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}