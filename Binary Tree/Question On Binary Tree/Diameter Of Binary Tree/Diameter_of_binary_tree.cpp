#include<iostream>
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

Node*bullidTree(Node*root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<< data <<endl;
    root->left = bullidTree(root->left);
    cout<<"Enter the data for inserting in right of "<< data <<endl;
    root->right = bullidTree(root->right);
    return root;
}
int height(Node*root){
    return root == NULL ? 0 : max(height(root->left),height(root->right))+1;
}
// Approach 1 : T(n) : O(n^2) and S(n) : O(1)
int diameter_Approach_one(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftDiameter = diameter_Approach_one(root->left); // Step 1 : Find Left SubTree Diameter
    int rightDiameter = diameter_Approach_one(root->right); // Step 2 : Find Right SubTree Diameter
    int Combination_of_leftDiameter_and_rightDiameter = height(root->left)+height(root->right)+1; // Finding Height Of left and Right Sub tree
    int ans = max(leftDiameter,max(rightDiameter,Combination_of_leftDiameter_and_rightDiameter)); // Maximum Of leftSubtree and rightSubTree and height of leftSubTree and Height SubTree = ans
    return ans;
}
// Approach 2 : T(n) : O(N) and S(N) : O(N)
pair<int,int> diameterFast(Node*root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0); 
        return p;
    }
    pair<int,int> left = diameterFast(root->left); 
    pair<int,int> right = diameterFast(root->right);
    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int Combination_of_leftDiameter_and_rightDiameter = left.second+right.second+1;
    pair<int,int> ans;
    ans.first = max(leftDiameter,max(rightDiameter,Combination_of_leftDiameter_and_rightDiameter));
    ans.second = max(leftDiameter,rightDiameter)+1;
    return ans;
}
int Diameter(Node*root){
    return diameterFast(root).first;
}
int main(){
    Node*root = NULL;
    root = bullidTree(root);
    int diameter = Diameter(root);
    cout<<"Diameter of Binary Tree is "<<diameter<<endl;
    return 0;
}