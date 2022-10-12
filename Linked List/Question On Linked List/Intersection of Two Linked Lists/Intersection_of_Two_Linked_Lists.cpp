#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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

void insertAtTail(Node *&ansHead, Node *&ansTail, int val)
{
    Node *temp = new Node(val);
    if (ansHead == NULL)
    {
        ansHead = temp;
        ansTail = temp;
    }
    else
    {
        ansTail->next = temp;
        ansTail = temp;
    }
}
// T(n) = O(n) and S(n) = O(1);
Node *Intersection_LinkedList(Node *&head1, Node *&head2)
{
    Node *current1 = head1;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (current1 != NULL)
    {
        Node *current2 = head2;
        while (current2 != NULL)
        {
            if (current1->data == current2->data)
            {
                insertAtTail(ansHead, ansTail, current1->data);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return ansHead;
}
// Approach 2 : Optimal Solution : using set data structre : T(n) = O(m+n) and S(n) : O(m+n)
Node *findIntersection(Node *head1, Node *head2)
{

    unordered_set<int> seen;
    Node *current1 = head1;
    Node *current2 = head2;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (current2 != NULL)
    {
        seen.insert(current2->data);
        current2 = current2->next;
    }
    while (current1 != NULL)
    {
        if (seen.find(current1->data) != seen.end())
        {
            insertAtTail(ansHead, ansTail, current1->data);
        }
        current1 = current1->next;
    }
    return ansHead;
}
int main()
{
    // 1st Linked List
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

    // Second Linked List
    Node *second1 = new Node(1);
    Node *second2 = new Node(5);
    Node *second3 = new Node(3);
    Node *second4 = new Node(6);
    Node *second5 = new Node(7);
    second1->next = second2;
    second2->next = second3;
    second3->next = second4;
    second4->next = second5;
    second5->next = nullptr;
    cout << "First Linked List : " << endl;
    display(node1);
    cout << "Second Linked List : " << endl;
    display(second1);
    // Node *ans = Intersection_LinkedList(node1, second1);
    Node *ans = findIntersection(node1, second1);
    cout << "Intersection Of Two Linked List Is : " << endl;
    display(ans);
    return 0;
}