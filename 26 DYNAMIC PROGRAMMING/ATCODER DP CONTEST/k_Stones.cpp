// https://atcoder.jp/contests/dp/tasks/dp_k

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int rec(vector<ll>& a,ll k,vector<int>& dp)
{
    
    if(dp[k] != -1) return dp[k];
    ll n = a.size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(k < a[i]) break;
        if(rec(a,k-a[i],dp) == 0)
        {
            ans = 1;
            break;
        }
    }
    return dp[k] = ans;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> dp(k+1,-1);
    int ans = rec(a,k,dp);
    if(ans) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}