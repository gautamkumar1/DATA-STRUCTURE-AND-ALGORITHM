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
void display(Node *head)
{
    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != NULL);
    cout << endl;
}
int getLength(Node *head)
{
    int i = 0;
    do
    {
        head = head->next;
        i++;
    } while (head != NULL);
    return i;
}
// insert at first
Node *insertAtStart(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
}
// Insert at end
Node *insertAtEnd(Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
        return tail;
    }
}
// Insert at anyPosition / Middle
Node *InsertAtAnyPosition(Node *&head, int pos, int data)
{
    if (pos == 1)
    {
        insertAtStart(head, data);
        return head;
    }
    Node *temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    // Insert at end
    if (temp->next == NULL)
    {
        insertAtEnd(head, data);
        return head;
    }
    // Insert at mid/AnyIndex/AnyPosition
    Node *NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
    return head;
}
int main()
{
    Node *head = new Node(4);
    Node *node2 = new Node(5);
    Node *node3 = new Node(6);
    Node *node4 = new Node(7);
    head->prev = NULL;
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
    display(head);
    // head = insertAtStart(head,3);
    // Node*tail = insertAtEnd(tail,8);
    // display(tail);
    // cout<<"Len: "<<getLength(head)<<endl;
    head = InsertAtAnyPosition(head, 4, 245);
    display(head);
    return 0;
}