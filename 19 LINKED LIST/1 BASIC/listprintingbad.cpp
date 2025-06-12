#include<iostream>
using namespace std;
class Node
{
    public:
    int val; //VALUE OF A SINGLE NODE
    Node* next; // ADDRESS OF THE NEXT LINKED NODE
    Node (int val) // CONSTRUCTOR FOR NODE INITIALISATION
    {
        this->val = val;
        this->next = NULL;
    }
};
int main()
{
    // CREATING SEPARATE NODES
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    // CREATING THE LINKED LIST
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Node temp = a;
    while(true)
    {
        cout<<temp.val<<" ";
        if(temp.next == NULL) break;
        temp = *(temp.next);
    }
    return 0;
}