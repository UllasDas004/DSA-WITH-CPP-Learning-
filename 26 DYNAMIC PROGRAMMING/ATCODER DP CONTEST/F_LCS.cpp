// https://atcoder.jp/contests/dp/tasks/dp_f

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,t;
    cin>>s>>t;
    ll ns = s.size(),nt = t.size();
    vector<vector<int>> dp(ns+1,vector<int>(nt+1,0));
    for(int i=1;i<=ns;i++)
    {
        for(int j=1;j<=nt;j++)
        {
            if(s[i-1] == t[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = ns,j = nt;
    string ans = "";
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}