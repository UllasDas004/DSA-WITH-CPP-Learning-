#include<iostream>
#include<climits>
#include<queue>
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
void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(q.size())
    {
        int n = q.size();
        while(n--)
        {
            Node* temp = q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<endl;
    }
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
    levelOrder(a);
    return 0;
}