#include<iostream>
#include<climits>
using namespace std;
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void predisplay(Node* root)
{
    if(root == NULL) return;
    cout<<root->val<<" ";       //WORK
    predisplay(root->left);     //CALL 1
    predisplay(root->right);    //CALL 2
}
void indisplay(Node* root)
{
    if(root == NULL) return;
    indisplay(root->left);     //CALL 1
    cout<<root->val<<" ";   //WORK
    indisplay(root->right);    //CALL 2
}void postdisplay(Node* root)
{
    if(root == NULL) return;
    postdisplay(root->left);     //CALL 1
    postdisplay(root->right);    //CALL 2
    cout<<root->val<<" ";   //WORK
}
int main()
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout<<"Pre-Order : ";
    predisplay(a);
    cout<<endl;
    cout<<"In-Order : ";
    indisplay(a);
    cout<<endl;
    cout<<"Post-Order : ";
    postdisplay(a);
    cout<<endl;
    return 0;
}