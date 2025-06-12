#include<iostream>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    queue<pair<TreeNode*,int>> q;
    unordered_map<int,int> mp; // <level,root-.val>
    q.push({root,0});
    while(q.size())
    {
        TreeNode* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(mp.find(level) == mp.end()) mp[level] = temp->val;
        if(temp->left) q.push({temp->left,level-1});
        if(temp->right) q.push({temp->right,level+1});
    }
    int mn = INT_MAX,mx = INT_MIN;
    for(auto ele : mp)
    {
        int a = ele.first;
        mx = max(mx,a);
        mn = min(mn,a);
    }
    for(int i=mn;i<=mx;i++)
    cout<<mp[i]<<" ";
    cout<<endl;
    return 0;
}
