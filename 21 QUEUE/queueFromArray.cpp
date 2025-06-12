#include<iostream>
using namespace std;
class Queue
{
    public:
    int q[10];
    int f,b,size;
    Queue()
    {
        f = 0;
        b = 0;
        size = 0;
    }
    void push(int val)
    {
        if(b == 10)
        {
            cout<<"Overflow!"<<endl;
            return;
        }
        q[b] = val;
        b++;
        size++;
    }
    void pop()
    {
        if(f == b)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        cout<<q[f]<<endl;
        f++;
        size--;
    }
    int front()
    {
        if(f == b)
        {
            cout<<"Underflow!"<<endl;
            return -1;
        }
        return q[f];
    }
    bool isEmpty()
    {
        if(b == f) return true;
        else return false;
    }
    bool isFull()
    {
        if(b == 10) return true;
        else return false;
    }
    void display()
    {
        if(b == f)
        {
            cout<<"Underflow!"<<endl;
            return;
        }
        for(int i=f;i<b;i++)
        cout<<q[i]<<" ";
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
    cout<<q.front()<<endl;
}