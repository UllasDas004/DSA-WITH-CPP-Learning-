#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int h(int n,vector<int>& dp)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int sum = 0;
    for(int i=1;i<=6;i++)
    {
        if(n-i<0) break;
        sum += h(n-i,dp);
        sum %= 1000000007;
    }
    return dp[n] = sum%1000000007;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<h(n,dp);
    return 0;
}