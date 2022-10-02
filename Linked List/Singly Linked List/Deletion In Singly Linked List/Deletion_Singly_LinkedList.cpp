#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor for free memory
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete (next);
            this->next = NULL;
        }
        cout << "Memeory is free for node with data is " << value << endl;
    }
};
void display(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// Delete at First
Node *DeleteAtFirst(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    // Memory free for start node
    delete temp;
    return head;
}
// Delete At End
Node *DeleteAtEnd(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    current->next = NULL;
    // Memory free for last Node
    delete (current);
    return head;
}

// Delete At AnyPosition
Node *DeleteAtAnyPosition(int position, Node *&head)
{
    if (position == 1)
    {
        DeleteAtFirst(head);
        return head;
    }
    else
    {
        // Delete at middle or Delete at last
        Node *prev = NULL;
        Node *current = head;
        int i = 1;
        while (i < position)
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete (current);
        return head;
    }
}
// Delete at anyValue
Node *DeleteAtAnyValue(Node *&head, int value)
{
    if (head->data == value)
    {
        DeleteAtFirst(head);
        return head;
    }
    else
    {
        Node *prev = NULL;
        Node *current = head;
        while (current->next != NULL && current->data != value)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next = NULL;
        delete (current);
        return head;
    }
}
int main()
{
    Node *head = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    display(head);
    // head = DeleteAtFirst(head);
    // head = DeleteAtEnd(head);
    // head = DeleteAtAnyPosition(4,head);
    head = DeleteAtAnyValue(head, 4);
    display(head);
    return 0;
}
