// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(vector<ll>& a,ll i,ll k,vector<ll>& dp)
{
    ll n = a.size();
    if(i == n-1) return 0;
    if(dp[i] != -1) return dp[i];
    ll ans = INT_MAX;
    for(int j=i+1;j<min(n,i+k+1);j++)
    ans = min(ans,abs(a[i]-a[j])+rec(a,j,k,dp));
    return dp[i] = ans;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),dp(n,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans = rec(a,0,k,dp);
    cout<<ans<<endl;
}