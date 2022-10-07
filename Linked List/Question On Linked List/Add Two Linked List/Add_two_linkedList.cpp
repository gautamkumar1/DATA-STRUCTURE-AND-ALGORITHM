#include<iostream>
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

Node*reverse(Node*&head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*prev = NULL;
    Node*forward = NULL;
    Node*current = head;
    while (current!=NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

void insertAtTail(Node*&head,Node*&tail,int val){
    Node*temp = new Node(val);
    if(head==NULL){
        head = temp;
        tail = temp;
        return ;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
// Approach 1 (Brute Force ) 
Node*add(Node*&first,Node*&second){
    int carry = 0;
    Node*ansHead = NULL;
    Node*anstail = NULL;
    while (first!=NULL && second!=NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum%10;
        insertAtTail(ansHead,anstail,digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }
    while (first!=NULL)
    {
        
        int sum = carry + first->data;
        int digit = sum%10;
        insertAtTail(ansHead,anstail,digit);
        carry = sum/10;
        first = first->next;
    }
    while (second!=NULL)
    {
        int sum = carry + second->data;
        int digit = sum%10;
        insertAtTail(ansHead,anstail,digit);
        carry = sum/10;
        second = second->next;
    }
    while (carry!=0)
    {
        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead,anstail,digit);
        carry = sum/10;
    }
    return ansHead;
}
// Approach 2 (Optimal Solution) 
Node*Add_Optimal_Solution(Node*&first,Node*&secound){
    int carry = 0;
    Node*ansHead = NULL;
    Node*ansTail = NULL;
    while (first!=NULL || secound!=NULL || carry!=0)
    {
        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        int val2  = 0;
        if(secound!=NULL){
            val2 = secound->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum %10;
        insertAtTail(ansHead,ansTail,digit);
        carry = sum/10;
        if(first!=NULL){
            first = first->next;
        }
        if(secound!=NULL){
            secound = secound->next;
        }
    }
    return ansHead;
}
Node*AddTwoLinkedList(Node*&first,Node*&second){
    // Step 1 : reverse both linked list
    first = reverse(first);
    second = reverse(second);
    // step 2 : add two linked list
    // Node*ans = add(first,second); // Brute force method using in add function
    Node*ans = Add_Optimal_Solution(first,second);
    // step 3 : now reverse ans then return ans
    ans = reverse(ans);
    return ans;
}

void display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    // First Linked List create
    Node*first = new Node(4);
    Node*node2 = new Node(5);
    first->next = node2;
    node2->next = NULL;
    // Second linked list created
    Node *second = new Node(3);
    Node*second2 = new Node(5);
    Node*second3 = new Node(5);
    second->next = second2;
    second2->next = second3;
    second3->next = NULL;
    cout<<"First linked list data are ";
    display(first);
    cout<<"Second linked list data are ";
    display(second);
    Node*ans = AddTwoLinkedList(first,second);
    cout<<"Sum of two linked list are ";
    display(ans);
    return 0;
}