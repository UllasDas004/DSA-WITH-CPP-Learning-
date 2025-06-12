#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Queue
{
    public:
    Node* front;
    Node* back;
    int size;
    Queue()
    {
        front = NULL;
        back = NULL;
        size = 0;
    }
    void push(int val)
    {
        Node* t = new Node(val);
        if(front == NULL)
        front = back = t;
        else
        {
            back->next = t;
            back = t;
        }
        size++;
    }
    void pop()
    {
        if(front == NULL)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        free(temp);
        size--;
    }
    int getFront()
    {
        if(front == NULL)
        {
            cout<<"Underflow!"<<endl;
            return -1;
        }
        return front->val;
    }
    void display()
    {
        if(front == NULL)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        Node* temp = front;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    cout<<q.size<<endl;
    q.pop();
    cout<<q.getFront()<<endl;
}