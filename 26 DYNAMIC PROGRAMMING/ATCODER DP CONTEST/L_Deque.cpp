// https://atcoder.jp/contests/dp/tasks/dp_l

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll rec(vector<ll>& a,int f,int r,vector<vector<ll>>& dp)
{
    if(f == r) return a[f];
    if(dp[f][r] != -1) return dp[f][r];
    ll ans = max(a[f] - rec(a,f+1,r,dp),a[r] - rec(a,f,r-1,dp));
    return dp[f][r] = ans;
}
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans = rec(a,0,n-1,dp);
    cout<<ans<<endl;
}