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

long long MultipliyTwoLL(Node*l1,Node*l2){
    // Mode Value 1o^9+7 = 1000000007
    Node*current1 = l1;
    Node*current2 = l2;
    long long int num1 = 0;
    long long int num2 = 0;
    long long int ans = 0;
    long long int mod = 1000000007;
    while (current1!=NULL)
    {
        num1 = (num1*10+(current1->data))%mod;
        current1 = current1->next;
    }
    while (current2!=NULL)
    {
        num2 = (num2*10+(current2->data))%mod;
        current2 = current2->next;
    }
    ans = (num1*num2)%mod;
    return ans;
}
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}
int main(){
    // Linked list 2
    Node*node1 = new Node(3);
    Node*node2 = new Node(2);
    // Linked List 1
    Node*node3 = new Node(2);
    node1->next = node2;
    node2->next = NULL;
    node3->next = nullptr;
    cout<<"First linked list is : "<<endl;
    display(node1);
    cout<<"Second linked list is : "<<endl;
    display(node3);
    long long int ans = MultipliyTwoLL(node1,node3);
    cout<<"Multiplication Of Two LL is : "<<ans<<endl;
    return 0;
}