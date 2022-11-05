/*
Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
*/

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
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data from inserting left of "<<data<<endl;
    root->left = BullidTree(root->left);
    cout<<"Enter the data from inserting right of "<<data<<endl;
    root->right = BullidTree(root->right);
    return root;
}
void solve(Node *root,int sum,int&Maxsum,int len,int&MaxLen){
    if(root==NULL){
        if(len>MaxLen){
            Maxsum = sum;
            MaxLen = len;
        }
        else if(len==MaxLen){
            Maxsum = max(sum,Maxsum);
        }
        return ;
    }
    sum+=root->data;
    solve(root->left,sum,Maxsum,len+1,MaxLen);
    solve(root->right,sum,Maxsum,len+1,MaxLen);
}
int sumOfLongRootToLeafPath(Node *root){
    int sum = 0;
    int MaxSum = INT_MIN;
    int len = 0;
    int MaxLen = 0;
    solve(root,sum,MaxSum,len,MaxLen);
    return MaxSum;
}

int main(){
    Node*root = NULL;
    root = BullidTree(root);
    int ans = sumOfLongRootToLeafPath(root);
    cout<<"Sum Of Long Root To Leaf Path Is "<<ans<<endl;
    return 0;
}