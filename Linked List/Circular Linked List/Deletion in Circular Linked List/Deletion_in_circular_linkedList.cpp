#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node(){
        int value = this->data;
        if (this->next!=NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"\nMemory Free Is With Node Data is "<<value<<endl;
    }
};

void display(Node*head){
    Node*temp = head;
    if (head==NULL)
    {
        cout<<"Linked List Is Empty"<<endl;
    }
    if (head!=NULL)
    {
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp!=head);
        
    }
}

Node*DeletionAtValue(Node*&tail,int value){
    Node*current = tail;
    Node*previous = current->next;
    while (current->data!=value)
    {
        previous = current;
        current = current->next;
    }
    // 1 Linked List
    if (current==previous)
    {
        tail = NULL;
        return tail;
    }
    // 2 Linked List
    if (tail == current)
    {
        tail = previous;
        return tail;
    }
    previous->next = current->next;
    current->next = NULL;
    delete (current);
    return tail;
    
}

int main(){
    Node*node1 = new Node(4);
    Node*node2 = new Node(45);
    Node*node3 = new Node(55);
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    display(node1);
    node1 = DeletionAtValue(node1,55);
    display(node1);
    return 0;
}