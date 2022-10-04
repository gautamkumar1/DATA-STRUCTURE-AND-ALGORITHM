#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node*kReverse(Node*head,int k){
    // Ek part solve krna hai baki phir recursion kar lega
    Node*prev = NULL;
    Node*forward = NULL;
    Node*current = head;
    int i = 1;
    while (current!=NULL && i<=k)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        i++;
    }
    // Remaing Part solve recursion
    if(forward!=NULL){
        head->next = kReverse(forward,k);
    }
    // Now head is pointing to prev so we set haed = prev
    head = prev;
    return head;   
}

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Node*node1 = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(3);
    Node*node4 = new Node(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    int k = 2;
    cout<<"Linked List Is : ";
    display(node1);
    node1 = kReverse(node1,k);
    cout<<"K Group Reverse Linked List Is : ";
    display(node1);
    return 0;
}