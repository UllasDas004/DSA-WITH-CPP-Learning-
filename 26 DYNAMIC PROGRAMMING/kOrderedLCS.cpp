#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

int f(vector<int>& a,vector<int>& b,int i,int j,int k,vector<vector<vector<int>>>& dp)
{
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0;
    if(a[i] == b[j]) ans = 1 + f(a,b,i+1,j+1,k,dp);
    else
    {
        if(k>0)
        ans = 1 + f(a,b,i+1,j+1,k-1,dp);
        ans = max(ans,f(a,b,i+1,j,k,dp));
        ans = max(ans,f(a,b,i,j+1,k,dp));
    }
    return dp[i][j][k] = ans;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cout<<f(a,b,0,0,k,dp);
    return 0;
}