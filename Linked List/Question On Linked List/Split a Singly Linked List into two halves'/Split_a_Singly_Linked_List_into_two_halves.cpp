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

int getlength(Node *ptr)
{
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}
// T(n) : O(n) and S(n) : O(1)
void SplitList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    int len = getlength(head);
    int half = len / 2;
    Node *current = head;
    Node *ansHead1 = NULL;
    Node *ansTail1 = NULL;
    Node *ansHead2 = NULL;
    Node *ansTail2 = NULL;
    if (half % 2 != 0)
    {
        int i = 1;
        while (i <= half && current != NULL)
        {
            int val = current->data;
            insertAtTail(ansHead2, ansTail2, val);
            current = current->next;
            i++;
        }
        while (current != NULL)
        {
            int val = current->data;
            insertAtTail(ansHead1, ansTail1, val);
            current = current->next;
        }
    }
    else
    {
        int i = 1;
        while (i <= half && current != NULL)
        {
            int val = current->data;
            insertAtTail(ansHead1, ansTail1, val);
            current = current->next;
            i++;
        }
        while (current != NULL)
        {
            int val = current->data;
            insertAtTail(ansHead2, ansTail2, val);
            current = current->next;
        }
    }
    cout << "First Half is : " << endl;
    display(ansHead1);
    cout << "Second Half is : " << endl;
    display(ansHead2);
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node*node4 = new Node(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    cout << "Original Linked List is : " << endl;
    display(node1);
    SplitList(node1);
    return 0;
}