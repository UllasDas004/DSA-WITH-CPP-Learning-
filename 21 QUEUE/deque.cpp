#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node *next,*prev;
    Node(int val)
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class Deque
{
    public:
    Node *front,*back;
    int size;
    Deque()
    {
        front = NULL;
        back = NULL;
        size = 0;
    }
    void pushFront(int val)
    {
        Node* t = new Node(val);
        if(size == 0)
        front = back = t;
        else
        {
            t->next = front;
            front->prev = t;
            front = t;
        }
        size++;
    }
    void pushBack(int val)
    {
        Node* t = new Node(val);
        if(size == 0)
        front = back = t;
        else
        {
            back->next = t;
            t->prev = back;
            back = t;
        }
        size++;
    }
    void popFront()
    {
        if(size == 0)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
        free(temp);
        size--;
    }
    void popBack()
    {
        if(size == 0)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        Node* temp = back;
        back = back->prev;
        temp->prev = NULL;
        back->next = NULL;
        free(temp);
        size--;
    }
    int getFront()
    {
        if(size == 0)
        {
            cout<<"Underflow!"<<endl;
            return -1;
        }
        return front->val;
    }
    int getBack()
    {
        if(size == 0)
        {
            cout<<"Underflow!"<<endl;
            return -1;
        }
        return back->val;
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
    Deque q;
    q.pushFront(10);
    q.pushBack(20);
    q.pushFront(30);
    q.pushFront(40);
    q.pushBack(50);
    q.display();
    cout<<q.size<<endl;
    q.popFront();
    q.display();
    cout<<q.getFront()<<endl;
    q.popBack();
    q.display();
}