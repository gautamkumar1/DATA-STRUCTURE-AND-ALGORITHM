#include <bits/stdc++.h>
using namespace std;
/*
Example :

Input:
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation:

4              5
|              |
1              6
 \             /
  8   -----  1
   |
   4
   |
  5
  |
  NULL
*/
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

int find_length(Node *ptr)
{
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}
// T(n) : O(L+S) and S(n) : O(1)
int intersectPoint(Node *head1, Node *head2)
{
    int len1 = find_length(head1);     // Finding length of first linkedlist
    int len2 = find_length(head2);     // Finding length of second linkedlist
    int difference = abs(len1 - len2); // Finding diffrence with absolute value
    Node *larger = NULL;
    Node *smaller = NULL;
    //   find larger length linked list
    if (len1 > len2)
    {
        larger = head1;
        smaller = head2;
    }
    else
    {
        larger = head2;
        smaller = head1;
    }
    // move d nodes in larger linked list
    int i = 1;
    while (i <= difference)
    {
        larger = larger->next;
        i++;
    }
    // then move one step each in both linked lists
    while (larger != smaller)
    {
        larger = larger->next;
        smaller = smaller->next;
    }
    return larger->data; // This is the intersection Point
}

int main()
{
    Node *node1 = new Node(11); // First linked list head
    Node *node2 = new Node(24);
    Node *node3 = new Node(33);
    Node *node4 = new Node(7);
    Node *node5 = new Node(8);
    Node *node6 = new Node(9);
    Node *node8 = new Node(63);
    Node *node7 = new Node(51); // Second linked list head
    Node *node9 = new Node(70);
    // First linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = nullptr;
    // Second linked list
    node8->next = node9;
    node9->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = nullptr;
    cout << "First linked list : " << endl;
    display(node1);
    cout << "Second linked list : " << endl;
    display(node8);
    int intersection_Data = intersectPoint(node1, node8);
    cout << "Both linked list intersect at " << intersection_Data << " Element" << endl;
    return 0;
}

