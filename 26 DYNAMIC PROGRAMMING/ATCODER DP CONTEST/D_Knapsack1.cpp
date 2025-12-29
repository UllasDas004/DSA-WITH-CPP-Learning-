// https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(vector<vector<ll>>& a,int i,ll w,vector<vector<ll>>& dp)
{
    ll n = a.size();
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    ll ans = rec(a,i+1,w,dp);
    if(w-a[i][0] >= 0) ans = max(ans,a[i][1]+rec(a,i+1,w-a[i][0],dp));
    return dp[i][w] = ans;
}
int main()
{
    ll n,w;
    cin>>n>>w;
    vector<vector<ll>> a(n,vector<ll>(2)),dp(n,vector<ll>(w+1,-1));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    ll ans = rec(a,0,w,dp);
    cout<<ans<<endl;
}