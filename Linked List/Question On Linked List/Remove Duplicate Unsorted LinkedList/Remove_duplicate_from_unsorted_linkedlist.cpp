#include<bits/stdc++.h>
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

void Display(Node*ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
// Using Two LOOP : T(n) = O(n^2) and S(n) = O(1)
Node*DuplicateRemove(Node*&head){
    if(head==NULL){
        return head;
    }
    Node*current = head;
    while (current!=NULL)
    {
        Node*temp = current;
        while (temp->next!=NULL)
        {
            if(current->data == temp->next->data){
                Node*next_next = temp->next->next;
                delete(temp->next);
                temp->next = next_next;
            }
            else
            {
                temp = temp->next;
            }
            
        }
        current = current->next;
    }
    return head;
}
// Using Unordered set Data Structre : T(n) = O(n) and S(n) = O(1)
Node*RemoveDuplicate_UsingMap(Node*&head){
    unordered_set<int>seen;
    Node*current = head;
    if (current==NULL)
    {
        return head;
    }
    else
    {
        seen.insert(current->data);
    }
    
    
    while (current!=NULL && current->next!=NULL)
    {
        if (seen.find(current->next->data)!=seen.end())
        {
            Node*next_next = current->next->next;
            delete(current->next);
            current->next = next_next;
        }
        else
        {
            seen.insert(current->data);
            current = current->next;
        }
        
    }
    
    return head;
}
int main(){
    Node*node1 = new Node(1);
    Node*node2 = new Node(3);
    Node*node3 = new Node(2);
    Node*node4 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    cout<<"Linked list before removing duplicates : ";
    Display(node1);
    // node1 = DuplicateRemove(node1); // Using Two loop
    node1 = RemoveDuplicate_UsingMap(node1);
    cout<<"Linked list after removing duplicates : ";
    Display(node1);
    return 0;

}