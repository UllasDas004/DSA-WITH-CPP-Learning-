#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
int dp[10005][5005];
int f(vector<int>& c,vector<int>& a,int i,int x)
{
    if(dp[i][x] != -1) return dp[i][x];
    if(i == c.size()) return 0;
    if(x == 0)
    return dp[i][x] = a[i] + f(c,a,i+1,x+1);
    else if(x == c.size()-i)
    return dp[i][x] = c[i] + f(c,a,i+1,x-1);
    else
    return dp[i][x] = min(a[i] + f(c,a,i+1,x+1),c[i] + f(c,a,i+1,x-1));
}
int main()
{
    int n;
    cin>>n;
    vector<int> c(n),a(n);
    for(int i=0;i<n;i++)
    cin>>c[i]>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<a[0]+f(c,a,1,1);
    return 0;
}