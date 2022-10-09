/*
Example 1 :
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*bottom;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->bottom = nullptr;
    }
};

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->bottom;
    }
    cout<<"null"<<endl;
}
// T(n) = O(n*m) and S(n) = O(1)
Node*merge(Node*&first,Node*&second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->bottom==NULL){
        first->bottom = second;
        return first;
    }

    Node*current1 = first;
    Node*bottom1 = first->bottom;
    Node*current2 = second;
    Node*bottom2 = NULL;
    while (bottom1!=NULL && current2!=NULL)
    {
        if((current2->data >= current1->data) && (current2->data <= bottom1->data)){
            current1->bottom = current2;
            bottom2 = current2->bottom;
            current1->bottom = bottom2;
            current1 = current2;
            current2 = bottom2;
        }
        else
        {
            current1 = bottom1;
            bottom1 = bottom1->next;
            if(bottom1==NULL){
                current1->bottom = current2;
                return first;
            }
        }
        
    }
    return first;
    
}

Node*FlattenLinkedList(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    // Step 1 : Divide in Two halves , Fisrt and Second
    Node*first = head;
    Node*second = head->next;
    first->next = NULL;
    // Step 2 : To get right list in sorted order using Recursion
    second = FlattenLinkedList(second);
    // Step 3 :  Merge two halves , first and secodn using merge two sorted linked list logic
    Node*ans = merge(first,second);
    // Step 4 : return ans
    return ans;
}

int main(){
    Node*node1 = new Node(5);
    Node*node2 = new Node(10);
    Node*node3 = new Node(19);
    Node*node4 = new Node(28);
    Node*bottom1 = new Node(7);
    Node*bottom2 = new Node(8);
    Node*bottom3 = new Node(30);
    Node*bottom4 = new Node(20);
    Node*bottom5 = new Node(22);
    Node*bottom6 = new Node(50);
    Node*bottom7 = new Node(35);
    Node*bottom8 = new Node(40);
    Node*bottom9 = new Node(45);
    node1->next = node2;
    node1->bottom = bottom1;
    node1->bottom->bottom = bottom2;
    node1->bottom->bottom = bottom3;
    node2->next = node3;
    node2->bottom = bottom4;
    node3->next = node4;
    node3->bottom = bottom5;
    node3->bottom->bottom = bottom6;
    node4->next = NULL;
    node4->bottom = bottom7;
    node4->bottom->bottom = bottom8;
    node4->bottom->bottom = bottom9;
    display(node1);
    node1 = FlattenLinkedList(node1);
    display(node1);
    return 0;
}