#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> dp((1<<16),INT_MAX);
vector<ll> sums((1<<16),0);
ll calc(vector<vector<ll>>& c,int mask)
{
    ll ans = 0;
    for(int i=0;i<=16;i++)
    {
        for(int j=i+1;j<=16;j++)
        {
            if((mask&(1<<i)) != 0 && (mask&(1<<j)) != 0)
            ans += c[i][j];
        }
    }
    return ans;
}
void precompute(vector<vector<ll>>& c,int n)
{
    for(int mask=1;mask<=((1<<n)-1);mask++)
    sums[mask] = calc(c,mask);
}
ll f(vector<vector<ll>>& c,int mask)
{
    if(mask == 0) return 0;
    if(dp[mask] != INT_MAX) return dp[mask];
    ll ans = INT_MIN;
    for(int g=mask;g!=0;g = ((g-1)&mask))
    ans = max(ans,sums[g] + f(c,(mask^g)));
    return dp[mask] = ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<ll>> c(n,vector<ll>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>c[i][j];
    }
    precompute(c,n);
    ll ans = f(c,((1<<n)-1));
    cout<<ans<<endl;
    return 0;
}