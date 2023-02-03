//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getNodes(struct Node* root){
        if(root==NULL)
            return 0;
        int ans = 1+getNodes(root->left)+getNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node* root,int index,int totalnodes){
        if(root==NULL)
            return 1;
        if(index>=totalnodes){
            return 0;
        }
        else{
            bool left = isCBT(root->left,2*index+1,totalnodes);
            bool right = isCBT(root->right,2*index+2,totalnodes);
            return (left && right);
        }
    }
    bool isMaxOrder(struct Node* root){
        // Leaf Node as MaxHeap
        if(root->left == NULL && root->right==NULL)
            return 1;
        // Case 2 if only one node exits
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxOrder(root->left); 
            bool right = isMaxOrder(root->right);
            bool Combination = (root->data > root->left->data && root->data > root->right->data);
            return (left && right && Combination);
        }
        
    }
    bool isHeap(struct Node* root) {
        int totalnodes = getNodes(root);
        int index = 0;
        if(isCBT(root,index,totalnodes) && isMaxOrder(root))
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}