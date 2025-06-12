#include<iostream>
using namespace std;
class Node
{
    public:
    Node *prev; // STORES ADDRESS OF PREVIOUS NODE
    int val;
    Node *next; // STORES ADDRESS OF NEXT NODE
    // CONSTRUCTOR
    Node (int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
void display(Node *head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void displayRev(Node *tail)
{
    while(tail)
    {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int main()
{
    // CREATING NODES
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    // ESTABLISHING NEXT CONNECTIONS
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    // ESTABLISHING PREVIOUS CONNECTIONS
    b->prev = a;
    c->prev = b;
    d->prev = c;
    e->prev = d;
    
    display(a);
    displayRev(e);
    return 0;
}