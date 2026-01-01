// https://atcoder.jp/contests/dp/tasks/dp_h

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll rec(vector<string>& grid,int i,int j,vector<vector<ll>>& dp)
{
    ll n = grid.size(),m = grid[0].length();
    if(i == n-1 && j == m-1) return 1;
    if(i>=n || j>=m || grid[i][j] == '#') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = rec(grid,i+1,j,dp) + rec(grid,i,j+1,dp);
    return dp[i][j] = ans % MOD;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    ll ans = rec(grid,0,0,dp);
    cout<<ans % MOD<<endl;
}