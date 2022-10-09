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

Node* Merge(Node*first,Node*secound){
    if (first->next == NULL)
    {
        first->next = secound;
        return first;
    }
    Node*current1 = first;
    Node*next1 = current1->next;
    Node*current2 = secound;
    Node*next2 = NULL;
    while (next1!=NULL && current2!=NULL)
    {
        if ((current2->data >= current1->data) && (current2->data <= next1->data))
        {
            current1->next = current2;
            next2 = current2->next;
            current2->next = next1;
            current1 = current2;
            current2 = next2;
        }
        else
        {
            current1 = next1;
            next1 = next1->next;
            if (next1==NULL)
            {
                current1->next = current2;
                return first;
            }

        }
        
    }
    return first;
    
}

Node*MergeTwoSortedLinkedList(Node*first,Node*secound){
    if (first==NULL)
    {
        return secound;
    }
    if (secound==NULL)
    {
        return first;
    }
    if (first->data<=secound->data)
    {
        return Merge(first,secound);
    }
    else
    {
        return Merge(secound,first);
    }
}

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"null"<<endl;
}

int main(){
    // First Linked List
    Node*first = new Node(1);
    Node*node2 = new Node(3);
    Node*node3 = new Node(5);
    // Secound Linked List
    Node*secound = new Node(2);
    Node*node5 = new Node(4);
    Node*node6 = new Node(5);
    // First Linked List
    first->next = node2;
    node2->next = node3;
    node3->next = NULL;
    // Secound Linked List
    secound->next = node5;
    node5->next = node6;
    node6->next = NULL;
    cout<<"First Linked List Is : ";
    display(first);
    cout<<"Secound Linked List Is : ";
    display(secound);
    Node*ans = MergeTwoSortedLinkedList(first,secound);
    cout<<"Merge Sorted Linked List Is : ";
    display(ans);
    return 0;
}