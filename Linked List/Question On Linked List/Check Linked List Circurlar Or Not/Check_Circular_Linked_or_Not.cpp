#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = next;
    }
};

// Approach 1 Iterative

bool isCircular(Node* head){
    if(head==NULL){
        return 1;
    }
    Node*temp = head->next;
    while (temp!=NULL && temp!=head)
    {
        temp = temp->next;
    }
    if(temp == head){
        return 1;
    }
    return 0;
}

// Two Pointer Appproach

bool isCircular_Two_Pointer(Node*head){
    Node*slow = head;
    Node*fast = head->next;
    while (slow!=fast)
    {
        if (fast==NULL || fast->next == NULL){
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return 1;
    
}
void display(Node *head)
{
    if(head==NULL){
        cout<<"LinkedList Is Empty"<<endl;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main(){
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
    if(isCircular_Two_Pointer(head)){
        cout<<"Linked List Is A Circular"<<endl;
    }
    else
    {
        cout<<"LinkedList Is Not a Circular"<<endl;
    }
    return 0;
}

