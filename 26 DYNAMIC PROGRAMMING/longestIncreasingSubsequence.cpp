// Find the longest increasing subsequence of a given array
// We will use form 2 of DP
// Best LIS ending at every Level


#include<bits/stdc++.h>
using namespace std;
int dp[105];
int rec(vector<int>& a,int level)
{
    // Best LIS ending at level.
    // pruning
    if(level < 0) return 0;
    // basecase

    // cache check
    if(dp[level] != -1) return dp[level];
    // check and compute
    int ans = 1;
    for(int prevTaken=0;prevTaken<level;prevTaken++)
    {
        if(a[level] > a[prevTaken])
        ans = max(ans,1+rec(a,prevTaken));
    }
    // return
    return dp[level] = ans;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements with spaces :\n";
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=0;i<n;i++)
    ans = max(ans,rec(a,i));
    cout<<"The longest increasing subsequence is "<<ans<<endl;
}