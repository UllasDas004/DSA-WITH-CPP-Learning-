// https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
#define ll long long
// ll rec(vector<ll>& a,ll i,vector<ll>& dp)
// {
//     ll n = a.size();
//     if(i == n-1) return 0;
//     if(dp[i] != -1) return dp[i];
//     ll one = INT_MAX,two = INT_MAX;
//     if(i+1 < n) one = abs(a[i] - a[i+1]) + rec(a,i+1,dp);
//     if(i+2 < n) two = abs(a[i] - a[i+2]) + rec(a,i+2,dp);
//     return dp[i] = min(one,two);
// }
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n),dp(n);
    for(int i=0;i<n;i++) cin>>a[i];
    dp[n-1] = 0;
    dp[n-2] = abs(a[n-1] - a[n-2]);
    for(int i=n-3;i>=0;i--)
    dp[i] = min(abs(a[i]-a[i+1])+dp[i+1],abs(a[i]-a[i+2])+dp[i+2]);
    cout<<dp[0]<<endl;
}