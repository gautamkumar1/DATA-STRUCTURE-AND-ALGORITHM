/*
-> Head is Now top
-> Stack Empty Condition ( top == NULL )
-> stack full Condition when heap memory is exhausted ( ptr == NULL )
*/

#include <iostream>
using namespace std;
class linkedListSatck
{
    int data;
    int size;
    linkedListSatck *next;
    linkedListSatck(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    bool isEmpty(linkedListSatck *top)
    {
        if (top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool isFull(linkedListSatck *top)
    {
        linkedListSatck *newNode = new linkedListSatck(-1);
        if (newNode == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(linkedListSatck *top, int data)
    {
        linkedListSatck *newNode = new linkedListSatck(data);
        if (isFull(newNode))
        {
            cout << "Stack is overflow" << endl;
            return;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    int pop(linkedListSatck *top)
    {
        if (isEmpty(top))
        {
            cout << "Satck is underflow" << endl;
            return -1;
        }
        else
        {
            linkedListSatck *temp = top;
            top = top->next;
            int val = top->data;
            delete temp;
            return val;
        }
    }
};
