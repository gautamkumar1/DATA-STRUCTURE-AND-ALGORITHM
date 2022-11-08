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
    cout << "Enter the data from inserting in left of " << data << endl;
    root->left = BullidTree(root->left);
    cout << "Enter the data from inserting in right of " << data << endl;
    root->right = BullidTree(root->right);
    return root;
}
Node *createMappingParent(Node *root, int target, unordered_map<Node *, Node *> &nodeToParent)
{
    // mapping for node to its parent
    // as for every node ,its left chil ,right child and its parent will burn
    // we can access left and right. but for parent we need mapping
    if (root == NULL)
    {
        return NULL;
    }
    Node *result = NULL;
    queue<Node *> q;
    nodeToParent[root] = NULL;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode->data == target)
        {
            result = frontNode;
        }
        if (frontNode->left != NULL)
        {
            nodeToParent[frontNode->left] = frontNode; // Mapping for its parent node
            q.push(frontNode->left);
        }
        if (frontNode->right != NULL)
        {
            nodeToParent[frontNode->right] = frontNode; // mapping for its parent node
            q.push(frontNode->right);
        }
    }
    return result;
}

int MinimumBurnTree(Node *&targetNode, unordered_map<Node *, Node *> &nodeToParent)
{
    int ans = 0; // time to burn tree.
    unordered_map<Node *, bool> visited;
    ; // creating a map to check if that node is already visited or not
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;
    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (frontNode->left != NULL && !visited[frontNode->left])
            {
                flag = true;
                q.push(frontNode->left);
                visited[frontNode->left] = true;
            }
            if (frontNode->right != NULL && !visited[frontNode->right])
            {
                flag = true;
                q.push(frontNode->right);
                visited[frontNode->right] = true;
            }
            if (nodeToParent[frontNode] && !visited[nodeToParent[frontNode]])
            { // checking parent node visited or not
                flag = true;
                q.push(nodeToParent[frontNode]);
                visited[nodeToParent[frontNode]] = true;
            }
        }
        if (flag == true)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    // 3 steps :-
    // 1) Create node to its parent mapping.
    // 2) Finding target node.
    // 3) Burn Tree in minimum time.
    unordered_map<Node *, Node *> nodeToParent;
    Node *targetNode = createMappingParent(root, target, nodeToParent);
    int ans = MinimumBurnTree(targetNode, nodeToParent);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = BullidTree(root);
    int target = 8;
    int ans = minTime(root, target);
    cout << "Minitime Time To Burn Tree is " << ans << endl;
    return 0;
}