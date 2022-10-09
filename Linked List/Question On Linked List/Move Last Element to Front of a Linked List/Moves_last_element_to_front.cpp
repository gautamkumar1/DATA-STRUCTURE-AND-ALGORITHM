#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}
Node *MoveLastElementToFront(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    int val = temp->data;
    prev->next = temp->next;
    delete (temp->next);
    temp->next = NULL;
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}
int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    cout << "Before move last element to front element in linked list : " << endl;
    display(node1);
    node1 = MoveLastElementToFront(node1);
    cout << "After move last element to front element in linked list : " << endl;
    display(node1);
    return 0;
}
