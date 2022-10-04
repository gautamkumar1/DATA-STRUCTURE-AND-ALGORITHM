#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void reverseDoublyLinkedList(Node *head)
{
   Node*tail = head; 
   while (tail->next != NULL) {
        tail = tail->next;
    }
    while (tail != head) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << tail->data << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
    reverseDoublyLinkedList(node1);
    return 0;
}