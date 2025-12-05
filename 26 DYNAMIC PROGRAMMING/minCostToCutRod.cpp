// There is a rod of n length
// on that rod there are n-1 cutpoints
// one cut costs the length of the rod
// we need to find the minimum cost to cut it into n pieces

#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int rec(vector<int>& cutPoints,int l,int r)
{
    if(l+1 == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = INT_MAX;
    int diff = cutPoints[r] - cutPoints[l];
    for(int p=l+1;p<r;p++)
    ans = min(ans,diff+rec(cutPoints,l,p)+rec(cutPoints,p,r));
    return dp[l][r] = ans;
}

int main()
{
    int len,n;
    cout<<"Enter the length of the rod:- ";
    cin>>len;
    cout<<"Enter the number of cut points:- ";
    cin>>n;
    vector<int> cutPoints(n+2);
    cutPoints[0] = 0;
    cout<<"Enter the cut points:- ";
    for(int i=1;i<n+1;i++) cin>>cutPoints[i];
    cutPoints[n+1] = len;
    memset(dp,-1,sizeof(dp));
    int ans = rec(cutPoints,0,n+1);
    cout<<"Minimum cost is "<<ans<<endl;
    return 0;
}