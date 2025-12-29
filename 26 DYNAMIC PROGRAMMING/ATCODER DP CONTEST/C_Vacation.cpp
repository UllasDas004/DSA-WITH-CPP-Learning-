// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(vector<vector<ll>>& a,int i,int prev,vector<vector<ll>>& dp)
{
    ll n = a.size();
    if(i == n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];
    ll ans = 0;
    for(int j=0;j<3;j++)
    {
        if(j != prev)
        ans = max(ans,a[i][j]+rec(a,i+1,j,dp));
    }
    return dp[i][prev] = ans;
}
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(3)),dp(n,vector<ll>(4,-1));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    ll ans = rec(a,0,3,dp);
    cout<<ans<<endl;
}