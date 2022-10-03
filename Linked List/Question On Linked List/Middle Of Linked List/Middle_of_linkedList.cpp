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
// Approach 1
int getLength(Node*ptr){
    int c = 0;
    while (ptr!=NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
    
}
// Approach 1 -> Time complexity : T(n) = O(n)+O(n/2) ; T(n) = O(n) , Where N is total number of nodes
Node*MiddleOfLinkedList(Node*&head){
    // Node empty and 1 node
    if (head==NULL || head->next == NULL)
    {
        return head;
    }
    // Only Two Node
    if (head->next->next==NULL)
    {
        return head->next;
    }
    
    Node*temp = head;
    int len = getLength(temp);
    int mid = (len/2);
    int i = 1;
    while (i<=mid)
    {
        temp = temp->next;
        i++;
    }
    return temp;
    
}
// Approach 2 -> Slow and Fast Pointer (Two Pointer) : T(n) = O(n)
Node*getMiddle(Node*&head){
    // Node empty and 1 node
    if (head==NULL || head->next == NULL)
    {
        return head;
    }
    // Only Two Node
    if (head->next->next==NULL)
    {
        return head->next;
    }
    Node*slow = head;
    Node*fast = head->next;
    while (fast!=NULL)
    {
        fast = fast->next;
        if (fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
    
}
void display(Node*ptr){
    if (ptr==NULL)
    {
        cout<<"Linked List Is Empty"<<endl;
    }
    
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    
}
int main(){
    Node*node1 = new Node(4);
    Node*node2 = new Node(9);
    Node*node3 = new Node(8);
    Node*node4 = new Node(7);
    Node*node5 = new Node(77);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    display(node1);
    // node1 = MiddleOfLinkedList(node1);
    node1 = getMiddle(node1);
    display(node1);
    return 0;
}