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

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"null"<<endl;
}
int getLength(Node*head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
int getNthFromLast(Node *head, int n)
{
       int len = getLength(head);
       if(n>len){
           return -1;
       }
       if(n==len){
           return head->data;
       }
       Node*first = head;
       Node*second = head;
       for(int i = 1; i<=n; i++){
           first = first->next;
       }
       while(first->next!=NULL){
           first = first->next;
           second = second->next;
       }
       return second->next->data;
}
int main(){
    Node*node1 = new Node(9);
    Node*node2 = new Node(2);
    Node*node3 = new Node(3);
    Node*node4 = new Node(10);
    Node*node5 = new Node(4);
    Node*node6 = new Node(11);
    Node*node7 = new Node(20);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;
    cout<<"Linked List : "<<endl;
    display(node1);
    int n = 2;
    int ans  = getNthFromLast(node1,n);
    cout<<n<<"th node data from last of linked list : "<<ans<<endl;
    return 0;

}