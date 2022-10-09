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

// Approach 1 : Replace is allow its means countzero,countOne,countTwo then replace in data: 
// Approach 1 : T(n) = O(n) and S(n) = O(1)

Node*Sort0s1s2s(Node*&head){
    if(head==NULL){
        return head;
    }
    // Count
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    Node*current = head;
    while (current!=NULL)
    {
        int val = current->data;
        if(val==0){
            countZero++;
        }
        else if(val==1){
             countOne++;
        }
        else if(val==2){
            countTwo++;
        }
        current = current->next;
    }
    // Now Replace
    current = head;
    while (current!=NULL)
    {
        if (countZero!=0)
        {
            current->data = 0;
            countZero--;
        }
        else if(countOne!=0){
            current->data = 1;
            countOne--;
        }
        else if(countTwo!=0){
            current->data = 2;
            countTwo--;
        }
        current = current->next;
    }
    return head;
       
}
// Approach 2 : Replace is not allow -> T(n) = O(n) and S(n)  = O(1)
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

Node*Sort0s1s2s_Replacement_NotAllow(Node*&head){
    Node*zeroHead = new Node(-1);
    Node*zeroTail = zeroHead;
    Node*oneHead = new Node(-1);
    Node*oneTail = oneHead;
    Node*twoHead = new Node(-1);
    Node*twoTail = twoHead;
    Node*current = head;
    while (current!=NULL)
    {
        int val = current->data;
        if(val==0){
            insertAtTail(zeroHead,zeroTail,val);
        }
        else if(val==1){
            insertAtTail(oneHead,oneTail,val);
        }
        else if(val==2){
            insertAtTail(twoHead,twoTail,val);
        }
        current = current->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
    
    
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
    Node *node1 = new Node(0);
    Node *node2 = new Node(1);
    Node *node3 = new Node(2);
    Node *node4 = new Node(0);
    Node *node5 = new Node(1);
    Node *node6 = new Node(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;
    display(node1);
    // node1 = Sort0s1s2s(node1);
    node1 = Sort0s1s2s_Replacement_NotAllow(node1);
    display(node1);
    return 0;
}