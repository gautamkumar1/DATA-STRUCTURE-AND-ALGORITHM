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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete (next);
            this->next = NULL;
        }
        cout << "Memory free node with data is " << value << endl;
    }
};
void display(Node *ptr)
{
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != NULL);
    cout << endl;
}
// Delete at first
Node *deleteAtFirst(Node *&head)
{
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete (temp);
    return head;
}
// Delete at end
Node *deleteAtEnd(Node *&head)
{
    Node *previous = NULL;
    Node *current = head;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    current->prev = NULL;
    previous->next = current->next;
    current->next = NULL;
    delete (current);
    return head;
}

// Delete at anyposition/mid/index
Node *deleteAtAnyPosition(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtFirst(head);
        return head;
    }
    else
    {
        // Delete at middle/anyposition/Last
        Node *previous = NULL;
        Node *current = head;
        int i = 1;
        while (i < pos)
        {
            previous = current;
            current = current->next;
            i++;
        }
        current->prev = NULL;
        previous->next = current->next;
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
    head->prev = NULL;
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
    display(head);
    // head = deleteAtFirst(head);
    // head = deleteAtEnd(head);
    head = deleteAtAnyPosition(head,4);
    display(head);
    return 0;
}