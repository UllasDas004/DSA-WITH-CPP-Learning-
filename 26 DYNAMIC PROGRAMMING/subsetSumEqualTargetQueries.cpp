/*
there are n integers and a target sum
find any subset that sum equal to target
but here are q queries also
*/


#include<bits/stdc++.h>
using namespace std;
int dp[101][10005];
bool rec(vector<int>& a,int level,int sum,int t,vector<int>& subset)
{
    // base case
    if(level == a.size())
    {
        if(sum == 0) return true;
        else return false;
    }
    //cache check
    if(dp[level][sum] != -1) return dp[level][sum];
    // transition
    bool ans = rec(a,level+1,sum,t,subset);
    if(sum-a[level] >= 0)
    {
        bool flag = rec(a,level+1,sum-a[level],t,subset);
        if(flag) subset.push_back(a[level]);
        ans |= flag;
    }
    return dp[level][sum] = ans;
}
int main()
{
    int n,q;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements with spaces :\n";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter the number of queries:- ";
    cin>>q;
    memset(dp,-1,sizeof(dp));
    while(q--)
    {
        int t;
        cout<<"Enter the target sum:- ";
        cin>>t;
        vector<int> subset;
        bool ans = rec(a,0,t,t,subset);
        if(ans)
        {
            cout<<"Yes possible."<<endl;
            for(int i=0;i<subset.size();i++) cout<<subset[i]<<" ";
            cout<<endl;
        }
        else cout<<"No not possible."<<endl;
    }
    return 0;
}