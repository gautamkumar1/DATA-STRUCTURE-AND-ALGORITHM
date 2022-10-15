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

Node*Segregate_Even_Odd(Node*&head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*evenHead = new Node(-1);
    Node*evenTail = evenHead;
    Node*oddHead = new Node(-1);
    Node*oddTail = oddHead;
    Node*current = head;
    while (current!=NULL)
    {
        int val = current->data;
        if(val%2==0){
            Node*EvenNumber = new Node(val);
            evenHead->next = EvenNumber;
            evenHead = EvenNumber;
        }
        else
        {
            Node*OddNumber = new Node(val);
            oddHead->next = OddNumber;
            oddHead = OddNumber;
        }
        current = current->next;
    }
    evenHead->next = oddTail->next;
    head = evenTail->next;
    return head;
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
    cout<<"Before Modified Linked List : "<<endl;
    display(node1);
    node1 = Segregate_Even_Odd(node1);
    cout<<"After Modified Linked List : "<<endl;
    display(node1);
    return 0;

}