#include <bits/stdc++.h> 
	class BinaryTreeNode {
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};
// step 1
void inorder(BinaryTreeNode* root,vector<int>&arr){
	if(root==NULL)
		return;
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);
}
// step 3
void FillPreorder(BinaryTreeNode* root,int&index,vector<int>&arr){
	if(root==NULL)
		return;
	root->data = arr[index++];
	FillPreorder(root->left, index, arr);
	FillPreorder(root->right, index, arr);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	inorder(root,arr);
	int index = 0;
	FillPreorder(root,index,arr);
	return root;
}

int main(){
    BinaryTreeNode* ans = convertBST(root);
    return 0;
}