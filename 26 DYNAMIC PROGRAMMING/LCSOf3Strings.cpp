// Given 3 strings have to find LCS

#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int rec(string a,string b,string c,int i,int j,int k)
{
    int n = a.length(),m = b.length(),o = c.length();
    if(i >= n || j >= m || k >= o) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0;
    ans = max(ans,rec(a,b,c,i+1,j,k));
    ans = max(ans,rec(a,b,c,i,j+1,k));
    ans = max(ans,rec(a,b,c,i,j,k+1));
    if(a[i] == b[j] && b[j] == c[k])
    ans = max(ans,1+rec(a,b,c,i+1,j+1,k+1));
    return dp[i][j][k] = ans;
}

int main()
{
    int n,m,o;
    cout<<"Enter the lengths of the 3 strings with spaces:- ";
    cin>>n>>m>>o;
    string a,b,c;
    cout<<"Enter the strings :\n";
    cin>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    int ans = rec(a,b,c,0,0,0);
    cout<<"The length of longest common subsequence is "<<ans<<endl;
    return 0;
}