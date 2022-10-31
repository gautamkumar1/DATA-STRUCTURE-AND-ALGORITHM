#include <iostream>
#include <vector>
#include<queue>
#include<map>
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

vector<int> verticalOrder(Node *root){
    if(root==NULL){
        return {};
    }
    vector<int> ans;
    // Create map of map like this : map<Horizontal Distance,map<level,array>>
    map<int,map<int,vector<int> > > nodes;
    // Create quuee like this : queue<pair<Node*,pair<HD,Level>>>
    queue<pair<Node*,pair<int,int> > > q;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node*,pair<int,int> > temp = q.front();
        q.pop();
        Node*frontnode = temp.first;
        int Horizontal_Distance = temp.second.first;
        int level = temp.second.second;
        nodes[Horizontal_Distance][level].push_back(frontnode->data);
        if(frontnode->left!=NULL){
            q.push(make_pair(frontnode->left,make_pair(Horizontal_Distance-1,level+1)));
        }
        if(frontnode->right!=NULL){
            q.push(make_pair(frontnode->right,make_pair(Horizontal_Distance+1,level+1)));
        }
    }
    for(auto i : nodes){ // i pointing to now -> int,map<int,vector<int>
        for(auto j : i.second){ // j pointing to now -> <int,vector<int>
            for(auto k : j.second){ // k pointing to now -> vector<int>
                ans.push_back(k);
            }  
        }
    }
    return ans;
}

int main(){
    Node*root = NULL;
    root = bullidTree(root);
    vector<int> ans = verticalOrder(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}