#include<iostream>
#include<queue>
using namespace std;
class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
bool isMax(TreeNode* root)
{
    if(root == NULL) return true;
    if(root->left && root->left->val > root->val) return false;
    if(root->right && root->right->val > root->val) return false;
    return isMax(root->left) && isMax(root->right);
}
int size(TreeNode* root)
{
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
bool isCBT(TreeNode* root)
{
    if(root == NULL) return true;
    queue<TreeNode*> q;
    q.push(root);
    int s = size(root);
    int count = 0;
    while(count < s)
    {
        TreeNode* temp = q.front();
        q.pop();
        count++;
        if(temp)
        {   
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while(q.size())
    {
        if(q.front()) return false;
        q.pop();
    }
    return true;
}
int main()
{
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(10);
    // root->right->left = NULL;
    root->right->left = new TreeNode(25);
    if(isMax(root) && isCBT(root)) cout<<"Tree is a MaxHeap."<<endl;
    else cout<<"Tree is not a MaxHeap."<<endl;
}