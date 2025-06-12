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
void display(Node* root)
{
    if(root == NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root)
{
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int product(Node* root)
{
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}
int size(Node* root)
{
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
int mxVal(Node* root)
{
    if(root == NULL) return INT_MIN;
    return max(root->val,max(mxVal(root->left),mxVal(root->right)));
}
int mnVal(Node* root)
{
    if(root == NULL) return INT_MAX;
    return min(root->val,min(mnVal(root->left),mnVal(root->right)));
}
int level(Node* root)
{
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
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
    Node* h = new Node(8);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    g->left = h;
    display(a);
    cout<<endl<<"sum = "<<sum(a)<<endl;
    cout<<"Product = "<<product(a)<<endl;
    cout<<"Number of nodes = "<<size(a)<<endl;
    cout<<"Maximum = "<<mxVal(a)<<endl;
    cout<<"Minimum = "<<mnVal(a)<<endl;
    cout<<"Level = "<<level(a)<<endl;
    return 0;
}