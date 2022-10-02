#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node*next;
Node(int data){
  this->data = data;
  this->next = NULL;
}
};
void display(Node* &head){
  Node*temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}
// Insertion at first
Node*insertionAtFirst(Node*&head,int data){
  Node*newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  return head;
}
// Insertion at end
Node*insertionAtEnd(Node*&tail,int data){
  Node*newNode = new Node(data);
  tail->next = newNode;
  tail = tail->next;
  return tail;
}
// Insertion at position/Middle
Node*insertionAtPosition(Node*&head,int index,int data){
    // Insertion at one Index
    if (index==1)
    {
        insertionAtFirst(head,data);
        return head;
    }
    
    Node*temp = head;
    int i = 1;
    while (i<index-1)
    {
        temp = temp->next;
        i++;
    }
    
    Node*newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
    
    
}
int main() {
  Node *node1 = new Node(10);
  Node *node2 = new Node(11);
  Node *node3 = new Node(12);
  Node *node4 = new Node(13);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = NULL;
//   Insertion at first
//   node1 = insertionAtFirst(node1,9);
//   display(node1);
//   Insertion at end
//   node1 = insertionAtEnd(node1,14);
//   display(node1);
  // Insertion at Positiion/Middle
  display(node1);
  node1 = insertionAtPosition(node1,5,8);
  display(node1);
  return 0;

}