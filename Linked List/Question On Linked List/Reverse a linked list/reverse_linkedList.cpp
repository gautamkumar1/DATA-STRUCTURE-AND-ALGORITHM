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
// Apparoch 1 : (Iterative)
Node *reverseLinkedList(Node *&head)
{
    // Empty list or 1 node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *previous = NULL;
    Node *forward = NULL;
    Node *current = head;
    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    // Now perivous is pointing to head so
    head = previous;
    return head;
}

// Apparoch 2 : Recursive 1
void Solve1(Node*&head,Node*prev,Node*curr){
    // Base Case
    if (curr==NULL)
    {
        head = prev;
        return ;
    }
    Node*forward = curr->next;
    Solve1(head,curr,forward);
    curr->next = prev;
}
Node*Recursive_Reverse_LinkedList(Node*&head){
    Node*prev = NULL;
    Node*curr = head;
    Solve1(head,prev,curr);
    return head;
    
}
// Apporach 3 
Node*reverseLinkedList_Recursive_02(Node*head){
    // Base Case
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*smallPart = reverseLinkedList_Recursive_02(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallPart;
}
void display(Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "Linked List Is Empty" << endl;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    display(node1);
    // node1 = reverseLinkedList(node1); // Iterative Appoarch 1
    // node1 = Recursive_Reverse_LinkedList(node1); // Recursive Approach 1
    node1 = reverseLinkedList_Recursive_02(node1); // Recursive Approach 2
    display(node1);
    return 0;
}