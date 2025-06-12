#include<iostream>
#include<vector>
using namespace std;
class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(vector<int>& in,int& idx,TreeNode* root)
{
    if(root == NULL || idx>=in.size()) return;
    root->val = in[idx];
    preorder(in,++idx,root->left);
    preorder(in,++idx,root->right);
}
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(16);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    vector<int> in;
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->right)
        {
            TreeNode* pred = curr->right;
            while(pred->left && pred->left != curr)
            pred = pred->left;
            if(pred->left == NULL)
            {
                pred->left = curr;
                curr = curr->right;
            }
            else if(pred->left == curr)
            {
                pred->left = NULL;
                in.push_back(curr->val);
                curr = curr->left;
            }
        }
        else
        {
            in.push_back(curr->val);
            curr = curr->left;
        }
    }
    for(int i=0;i<in.size();i++) cout<<in[i]<<" ";
    cout<<endl;
    int idx = 0;
    preorder(in,idx,root);
    return 0;

}