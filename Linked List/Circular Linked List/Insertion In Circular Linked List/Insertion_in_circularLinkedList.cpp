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

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
// Circular linked list me head ya end se koii insertion nhi hota hai isliye hum value leke kar rahe hai
Node*InsertAtValue(Node*&tail,int element,int data){
    // Empty Circular Linked List
    if (tail==NULL)
    {
        Node*newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        return tail;
    }
    else
    {
        // assuming that element is persent
        Node*current = tail;
        while (current->data!=element)
        {
            current = current->next;
        }
        // out of loop element is find
        // step1 : create a new node
        Node*temp = new Node(data);
        // Step2: temp->next = current->next
        temp->next = current->next;
        // step3: current->next = temp;
        current->next = temp;
        return tail;

    }
    
}
int main()
{
    Node *head = new Node(40);
    Node *node2 = new Node(50);
    Node *node3 = new Node(60);
    Node *tail = new Node(70);
    // Linked Fisrt node to secound node
    head->next = node2;
    // Linked secound node to third node
    node2->next = node3;
    // Linled third node to fourth node(tail)
    node3->next = tail;
    // linked fourth node to head (first node)
    tail->next = head;
    display(head);
    /* STEP BY STEP INSERTION

    head = InsertAtValue(head,5,40); // Add in empty list
    display(head);
    head = InsertAtValue(head,40,41); // add after one node
    display(head);
    head = InsertAtValue(head,40,45); // add in midd / any position
    display(head);
    head = InsertAtValue(head,404,459); // add in midd / any position
    display(head);
    */
    return 0;
}