// https://atcoder.jp/contests/dp/tasks/dp_g

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(vector<vector<ll>>& graph,ll curr,vector<ll>& dp)
{
    if(dp[curr] != -1) return dp[curr];
    ll mx = 0;
    for(auto neighbor : graph[curr])
    mx = max(mx,1+rec(graph,neighbor,dp));
    return dp[curr] = mx;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> graph(n);
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
    }
    vector<ll> dp(n,-1);
    ll ans = 0;
    for(int i=0;i<n;i++) ans = max(ans,rec(graph,i,dp));
    cout<<ans<<endl;
}