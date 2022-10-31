#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*BullidTree(Node*root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if (data==-1)
    {
        return nullptr;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}

vector<int> BottomView(Node*root){
    if(root==NULL){
        return {};
    }
    vector<int> ans;
    // Create map like this : map<Horizontal_Distance,Data>
    map<int,int> nodes;
    // create queue like this : queue<pair<Node*,Horizontal_Distance>>
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node*frontNode = temp.first;
        int HD = temp.second;
        nodes[HD] = frontNode->data;
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,HD-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,HD+1));
        }
    }
     // Now Val pointing to like this : Val -> <int(HD),int(DATA)>
    for(auto val : nodes){
        ans.push_back(val.second);
    }
    return ans;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    vector<int> ans = BottomView(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}