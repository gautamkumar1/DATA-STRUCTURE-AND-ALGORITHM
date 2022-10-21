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

Node*reverse(Node*&head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*prev = NULL;
    Node*forward = NULL;
    Node*current = head;
    while (current!=NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

void insertAtTail(Node*&head,Node*&tail,int val){
    Node*temp = new Node(val);
    if(head==NULL){
        head = temp;
        tail = temp;
        return ;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node*add(Node*&first,Node*&second){
    first = reverse(first);
    second = reverse(second);
    Node*head = NULL;
    Node*tail = NULL;
    int carry = 0;
    while (first!=NULL || second!=NULL || carry!=0)
    {
        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second!=NULL){
            val2 = second->data;
        }
        int sum = val1+val2+carry;
        int digit = sum%10;
        insertAtTail(head,tail,digit);
        carry = sum/10;
        if(first!=NULL){
            first = first->next;
        }
        if(second!=NULL){
            second = second->next;
        }
    }
    head = reverse(head);
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
Node*AddOne(Node*head){
    Node*fisrt = head;
    Node*second = new Node(1);
    Node*ans = add(fisrt,second);
    return ans;
}

int main(){
    Node*node1 = new Node(9);
    Node*node2 = new Node(9);
    Node*node3 = new Node(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    cout<<"Before : "<<endl;
    display(node1);
    node1 = AddOne(node1);
    cout<<"After : "<<endl;
    display(node1);
    return 0;
}