#include<iostream>
#include<vector>
using namespace std;
void combinationSum(vector<int> ans,vector<int>& candidates,int target,int idx)
{
    if(target == 0)
    {
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    if(target < 0) return;
    for(int i=idx;i<candidates.size();i++)
    {
        ans.push_back(candidates[i]);
        combinationSum(ans,candidates,target-candidates[i],i);
        ans.pop_back();
    }
}
int main()
{
    int n;
    cout<<"Enter the size:- ";
    cin>>n;
    vector<int> candidates;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter umber"<<i+1<<":- ";
        int x;
        cin>>x;
        candidates.push_back(x);
    }
    int target;
    cout<<"Enter the target sum:- ";
    cin>>target;
    vector<int> ans;
    combinationSum(ans,candidates,target,0);
}