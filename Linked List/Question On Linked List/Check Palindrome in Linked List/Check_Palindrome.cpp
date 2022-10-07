#include<iostream>
#include<vector>
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
bool CheckPalindrome(vector<int>&arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    int flag = 0;
    while (left<=right)
    {
        if (arr[left]!=arr[right])
        {
            return 0;
        }
        else
        {
            left++;
            right--;
        }
        
    }
    return 1;
}
// Apporach 1 (Brute Force) : T(n) = O(n) and S(n) = O(1)
bool isPalindrome(Node*&head){
    vector<int>arr;
    Node*temp = head;
    while (temp!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return CheckPalindrome(arr);
}
Node*getMiddle(Node*&head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node*slow = head;
    Node*fast = head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node*reverse(Node*&head){
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
// Apporach 2 (Optimial Solution) : T(n) = O(n) and S(n) = O(1)
bool is_Linked_List_Palindrome(Node*&head){
    if(head==NULL || head->next == NULL){
        return 1;
    }
    // Step 1 : Find Mid
    Node*middle = getMiddle(head);
    //step2 -> reverse List after Middle
    Node*temp = middle->next;
    middle->next = reverse(temp);
    // Step 3 : compare both side values
    Node*head1 = head;
    Node*head2 = middle->next;
    while (head2!=NULL)
    {
        if(head1->data!=head2->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}
int main(){
    Node*node1 = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    Display(node1);
    if (is_Linked_List_Palindrome(node1))
    {
        cout<<"Linked list is palindrome"<<endl;
    }
    else
    {
        cout<<"Linked list is not palindrome"<<endl;
    }
   
    return 0;
}
