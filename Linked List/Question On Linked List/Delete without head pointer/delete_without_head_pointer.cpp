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
    } cout<<"null"<<endl;
}

void DeleteWithoutHeadPointer(Node*del){
    if(del==NULL){
        cout<<"Sorry null value cannot deleted"<<endl;
    }
    del->data = del->next->data;
    del-> next = del->next->next;
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
    cout<<"Before : "<<endl;
    display(node1);
    DeleteWithoutHeadPointer(node1);
    cout<<"After : "<<endl;
    display(node1);
}