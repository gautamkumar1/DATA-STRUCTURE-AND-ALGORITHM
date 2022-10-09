#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*random;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};

void printNodes(Node* head) {
        while(head != NULL) {
            cout << " head data : " << head->data <<" ";
            if(head ->random != NULL) {
                cout << " head random data : " << head -> random ->data<<" ";
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
        cout << endl;
    }
// Approach 1 : using Map data structre : T(n) = O(n) and S(n) = O(1)
void insertAtTail(Node*&head,Node*&tail,int val){
    Node*temp = new Node(val);
    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
Node*cloneLinkedList_Using_Map(Node*&head){
    // Step 1 : clone linked list using next pointer
    Node*cloneHead = NULL;
    Node*cloneTail = NULL;
    Node*current = head;
    while (current!=NULL)
    {
        insertAtTail(cloneHead,cloneTail,current->data);
        current = current->next;
    }
    // Step 2 : create a map for originalNode
    unordered_map<Node*,Node*> oldToNew;
    Node*cloneNode = cloneHead;
    Node*originalNode = head;
    while (originalNode!=NULL && cloneHead!=NULL)
    {
        oldToNew[originalNode] = cloneNode;
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    // Step 3 : copy random pointer
    cloneNode = cloneHead;
    originalNode = head;
    while (originalNode!=NULL && cloneNode!=NULL)
    {
        cloneNode->random = oldToNew[originalNode->random];
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    return cloneHead;
}

// Approach 2 : Changing Links Method : T(n) = O(n) and S(n) = O(1)
Node*CopyLinkedList(Node*&head){
    // Step 1 : Clone linked list using next Pointer
    Node*cloneHead = NULL;
    Node*cloneTail = NULL;
    Node*current = head;
    while (current!=NULL)
    {
        insertAtTail(cloneHead,cloneTail,current->data);
        current = current->next;
    }
    // Step 2 : insert nodes of Clone List in between originalList
    Node*cloneNode = cloneHead;
    Node*originalNode = head;
    while (originalNode!=NULL && cloneNode!=NULL)
    {
        Node*next_next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next_next;
        next_next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next_next;
    }
    // Step 3 : Copy Random Pointer
    Node*temp = head;
    while (temp!=NULL)
    {
        if(temp->next!=NULL){
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        temp = temp->next->next;
    }
    // step 4 : Revert step 2 to changes
    Node*clone = cloneHead;
    Node*original = head;
    while (original!=NULL && clone!=NULL)
    {
        original->next = clone->next;
        original = original->next;
        if(original!=NULL){
            clone->next = original->next;
        }
        clone = clone->next;
    }
    // Step 5 : return cloneHead
    return cloneHead;
    
    
}
int main(){
    Node*node1 = new Node(7);
    Node*node2 = new Node(13);
    Node*node3 = new Node(11);
    Node*node4 = new Node(10);
    Node*node5 = new Node(1);
    node1->next = node2;
    node1->random = NULL;
    node2->next = node3;
    node2->random = node1;
    node3->next = node4;
    node3->random = node5;
    node4->next = node5;
    node4->random = node3;
    node5->next = NULL;
    node5->random = node1;
    cout<<endl<<"          Original Linked List          "<<endl<<endl;
    printNodes(node1);
    // node1 = cloneLinkedList_Using_Map(node1);
    node1 = CopyLinkedList(node1); 
    cout<<endl<<"          Clone Linked List          "<<endl<<endl;
    printNodes(node1);
    return 0;


}