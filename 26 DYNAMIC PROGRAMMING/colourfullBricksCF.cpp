// https://codeforces.com/problemset/problem/1081/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll dp[2002][2002];
// this calculates basically combination(n,k+1)
ll rec(ll n,ll k)
{
    if(k >= n) return 0;
    if(k == 0) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    ll ans = rec(n-1,k) % MOD;
    if(k >= 1)
    {
        ans = (ans%MOD + rec(n-1,k-1)%MOD) % MOD;
    }
    return dp[n][k] = ans % MOD;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    ll ans = rec(n,k) % MOD;
    ans = (ans*m) % MOD;
    for(int i=1;i<=k;i++) ans = (ans*(m-1)) % MOD;
    cout<<ans<<endl;
}