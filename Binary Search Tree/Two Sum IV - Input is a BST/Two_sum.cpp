#include<iostream>
#include<vector>
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

Node*insertNodeInBST(Node*root,int value){
    if(root==NULL){
        root = new Node(value);
        return root;
    }
    // Inserting Node in right side
    if(value > root->data){
        
        root->right = insertNodeInBST(root->right,value);
    }
    // Inserting Node in left side
    else
    {
        root->left = insertNodeInBST(root->left,value);
    }
    return root;
}

void TakingInput(Node*&root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root = insertNodeInBST(root,data);
        cin>>data;
    }
}

void inorder(Node* root,vector<int>&arr){
    if(root==NULL)
        return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
bool twoSumInBST(Node* root, int target) {
	vector<int>arr;
    inorder(root,arr);
    int n = arr.size();
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==target){
            return 1;
        }
        else if(arr[left]+arr[right]<target){
            left++;
        }
        else{
            right--;
        }
    }
    return 0;
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    TakingInput(root);
    int tagert;
    cout<<"Enter the target : "<<endl;
    cin>>tagert;
    if(twoSumInBST(root,tagert)){
        cout<<"Yes,Sum is Found"<<endl;
    }
    else
    {
        cout<<"No,Sum is Not Found"<<endl;
    }
    
    return 0;
}