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
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void displayRec(Node* head)
{
    if(head == NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    cout<<head->val<<"->";
    displayRec(head->next);
}
void revDisplay(Node* head)
{
    if(head == NULL) return;
    revDisplay(head->next);
    cout<<head->val<<" ";
}
int size(Node* head)
{
    Node* temp = head;
    int size = 0;
    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
int main()
{
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);
    displayRec(a);
    revDisplay(a);
    cout<<endl;
    cout<<size(a);
    return 0;
}