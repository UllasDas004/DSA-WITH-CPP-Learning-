// https://codeforces.com/problemset/problem/607/b

#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int rec(vector<int>& a,int i,int j)
{
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1000;
    ans = min(ans,1+rec(a,i+1,j)); // removing one element
    if(i+1<a.size() && a[i] == a[i+1]) // special case where two consecutive are same
    ans = min(ans,1+rec(a,i+2,j));
    for(int k=i+2;k<=j;k++) // finding the best partition
    {
        if(a[i] == a[k])
        ans = min(ans,rec(a,i+1,k-1)+rec(a,k+1,j));
    }
    return dp[i][j] = ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans = rec(a,0,n-1);
    cout<<ans<<endl;
}