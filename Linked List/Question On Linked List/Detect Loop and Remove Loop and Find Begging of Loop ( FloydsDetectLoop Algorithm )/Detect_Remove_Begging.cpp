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

void print(Node*ptr){
    if(ptr==NULL){
        cout<<"Empty LinkedList"<<endl;
    }
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

// Detect LOOP using Map Data structre, map store key and value
bool isLoop(Node*head){
    if (head==NULL)
    {
        return false;
    }
    map<Node*,bool> visited;
    Node*temp = head;
    while (temp!=NULL)
    {
        if(visited[temp]==true){
            cout<<"Loop Present at Value is : "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
// Flyods Cycle Detect Loop Algorithm
Node*FloydsDetectLoop(Node*&head){
    if(head==NULL){
        return head;
    }
    Node*slow = head;
    Node*fast = head;
    while (slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* get_Beggining_Node_of_Loop(Node*&head){
    if(head==NULL){
        return head;
    }
    // Its means fast and slow point to one place in floyds function abhi hume slow ko head pe point krna hai or phir fast and slow ko ek ek step chalna hai jb slow and fast mil jayega tab hume beginning node of loop mil jayega
    Node*fast = FloydsDetectLoop(head); // now fast is pointing to detetect loop place
    if(fast==NULL){
        return head;
    }
    Node*slow = head; // now slow is pointing to head
    while (slow!=fast)
    {
        slow = slow->next; // one step
        fast = fast->next; // one step
    }
    if(slow==fast){ // found beggining node of loop
        return slow;
    }
}
Node*removeLoop(Node*&head){
    if (head==NULL)
    {
        return head;
    }
    Node*startLoop = get_Beggining_Node_of_Loop(head);
    if(startLoop==NULL){
        return head;
    }
    Node*temp = startLoop;
    while (temp->next!=startLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
    
    
}
int main(){
    Node*node1 = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(3);
    Node*node4 = new Node(4);
    Node*node5 = new Node(5);
    Node*node6 = new Node(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node1->next;
    // print(node1);
    Node*startNode = get_Beggining_Node_of_Loop(node1);
    cout<<endl;
    cout<<"Satrt loop at value is "<<startNode->data<<endl;
    cout<<endl;
    Node*AfterRemoveLOOP = removeLoop(node1);
    cout<<endl;
    cout<<"Now, after detecting and removing this loop the linked list will be: ";
    print(AfterRemoveLOOP);
    cout<<endl;

    if(FloydsDetectLoop(node1)!=NULL){ 
        cout<<endl<<"Loop Is Present In Linked List"<<endl;
    }
    else
    {
         cout<<"Loop Is Not Present In Linked List"<<endl;
    }
    return 0;
}