#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    } cout<<"null"<<endl;
}

Node*getMid(Node*head){
    Node*slow = head;
    Node*fast = head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node*merge(Node*left,Node*right){
    if(left==nullptr){
        return right;
    }
    if(right==nullptr){
        return left;
    }

    Node*temp = new Node(-1); // create dummy node to add data
    Node*head = temp;
    while (left!=NULL && right!=NULL)
    {
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
    }
    while (left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right!=NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    head = head->next;
    return head;
    
}
// T(n) = O(nlogn) and S(n) = O(logn)
Node*mergeSort(Node*head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*mid = getMid(head);
    Node*left = head;
    Node*right = mid->next;
    mid->next = nullptr;
    left = mergeSort(left);
    right = mergeSort(right);
    Node*ans = merge(left,right);
    return ans;
}

int main(){
    Node*node1 = new Node(4);
    Node*node2 = new Node(3);
    Node*node3 = new Node(2);
    Node*node4 = new Node(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    cout<<"Unsorted Linked Lis : ";
    display(node1);
    node1 = mergeSort(node1);
    cout<<"Sorted Linked List is ";
     display(node1);
     return 0;

}