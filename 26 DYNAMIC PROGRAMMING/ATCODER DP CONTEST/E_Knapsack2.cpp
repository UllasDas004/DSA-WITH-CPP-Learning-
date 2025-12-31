// https://atcoder.jp/contests/dp/tasks/dp_e

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(vector<vector<ll>>& a,int i,ll v,vector<vector<ll>>& dp)
{
    if(v == 0) return 0;
    ll n = a.size();
    if(v < 0 || i == n) return INT_MAX;
    if(dp[i][v] != -1) return dp[i][v];
    ll ans = rec(a,i+1,v,dp);
    ans = min(ans,a[i][0]+rec(a,i+1,v-a[i][1],dp));
    return dp[i][v] = ans;
}
int main()
{
    ll n,w,sum = 0;
    cin>>n>>w;
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        sum += a[i][1];
    }
    vector<vector<ll>> dp(n,vector<ll>(sum+1,-1));
    ll ans = 0;
    for(int v=sum;v>=0;v--)
    {
        if(rec(a,0,v,dp) <= w)
        {
            ans = v;
            break;
        }
    }
    cout<<ans<<endl;
}