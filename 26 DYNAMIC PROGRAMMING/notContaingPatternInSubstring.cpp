// given an integer n
// have to find no of substrings that does not contain "0100" as a substring

#include<bits/stdc++.h>
using namespace std;
int dp[100100][5];
int rec(int n,int i,int j)
{
    if(j == 4) return 0;
    if(i == n) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = rec(n,i+1,j+1);
    if(j <= 1) ans += rec(n,i+1,j);
    else ans += rec(n,i+1,((j << 1) & 3));
    return dp[i][j] = ans;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans = rec(n,0,0);
    cout<<"No of Binary strings are : "<<ans<<endl;
    return 0;
}