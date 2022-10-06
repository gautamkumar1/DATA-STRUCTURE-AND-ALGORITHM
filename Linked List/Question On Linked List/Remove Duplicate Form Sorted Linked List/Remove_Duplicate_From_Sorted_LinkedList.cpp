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

void Display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

Node*RemoveDuplicate(Node*&head){
    if (head==NULL)
    {
        return head;
    }
    Node*current = head;
    Node*next_next = NULL;
    while (current->next!=NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            delete(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
        
    }
    return head;
}

int main(){
    Node*node1 = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(2);
    Node*node4 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    cout<<"Before : ";
    Display(node1);
    node1 = RemoveDuplicate(node1);
    cout<<"After : ";
    Display(node1);
    return 0;

}