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

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
int getlen(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *rotate(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    int len = getlen(head);
    if (k == len)
    {
        return head;
    }
    Node *anshead = NULL;
    Node *anstail = NULL;
    Node *current = head;
    Node *temp = head;
    int i = 1;
    while (current != NULL && i <= k)
    {
        int val = current->data;
        insertAtTail(anshead, anstail, val);
        current = current->next;
        i++;
    }
    Node *tempHead = current;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = anshead;
    head = tempHead;
    return head;
}

int main(){
    Node*node1 = new Node(2);
    Node*node2 = new Node(4);
    Node*node3 = new Node(7);
    Node*node4 = new Node(8);
    Node*node5 = new Node(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    int k = 3;
    cout<<"Before Rotate Linked List is : "<<endl;
    display(node1);
    node1 = rotate(node1,k);
    cout<<"After Rotate Linked List is : "<<endl;
    display(node1);
    return 0;
}