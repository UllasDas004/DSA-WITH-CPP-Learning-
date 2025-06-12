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
    cout<<"Value of a through a = "<<a.val<<endl;
    cout<<"Value of b through b = "<<b.val<<endl;
    cout<<"Value of b through a = "<<(a.next)->val<<endl;
    cout<<"Value of c through c = "<<c.val<<endl;
    cout<<"Value of c through b = "<<(b.next)->val<<endl;
    cout<<"Value of c through a = "<<((a.next)->next)->val<<endl;
    cout<<"Value of d through d = "<<d.val<<endl;
    cout<<"Value of d through c = "<<(c.next)->val<<endl;
    cout<<"Value of d through b = "<<((b.next)->next)->val<<endl;
    cout<<"Value of d through a = "<<(((a.next)->next)->next)->val<<endl;
    return 0;
}