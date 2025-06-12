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
Node* construct(int arr[],int n)
{
    if(n == 0) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1,j = 2;
    while(q.size() && i<n)
    {
        Node* temp = q.front();
        q.pop();
        Node* l,*r;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j != n && arr[j] != INT_MIN) r = new Node(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l) q.push(l);
        if(r) q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}
void leftBoundary(Node* root)
{
    if(!root || (!root->left && !root->right)) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(!root->left) leftBoundary(root->right);
}
void leaves(Node* root)
{
    if(root == NULL) return;
    if(!root->left && !root->right) cout<<root->val<<" ";
    leaves(root->left);
    leaves(root->right);
}
void rightBoundary(Node* root)
{
    
    if(!root || (!root->left && !root->right)) return;
    rightBoundary(root->right);
    if(!root->right) rightBoundary(root->left);
    cout<<root->val<<" ";
}
void boundary(Node* root)
{
    leftBoundary(root);
    leaves(root);
    rightBoundary(root->right);

}
int main()
{
    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    boundary(root);
    return 0;
}