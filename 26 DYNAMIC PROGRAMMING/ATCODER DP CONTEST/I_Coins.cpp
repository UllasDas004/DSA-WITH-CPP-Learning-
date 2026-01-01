// https://atcoder.jp/contests/dp/tasks/dp_i

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool memo[3000][3000];
double dp[3000][3000];
double rec(vector<double>& a,int i,int h,int t)
{
    int n = a.size();
    if(t-h > n-i) return 0;
    if(i == n)
    {
        if(h > t) return 1;
        else return 0;
    }
    if(memo[i][h]) return dp[i][h];
    double ans = 0;
    ans += a[i]*rec(a,i+1,h+1,t);
    ans += (1-a[i])*rec(a,i+1,h,t+1);
    memo[i][h] = true;
    return dp[i][h] = ans;
}
int main()
{
    int n;
    cin>>n;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    memset(memo,false,sizeof(memo));
    double ans = rec(a,0,0,0);
    cout<<setprecision(10)<<ans<<endl;
}