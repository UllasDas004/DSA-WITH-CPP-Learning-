// https://atcoder.jp/contests/dp/tasks/dp_j

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool memo[301][301][301];
double dp[301][301][301];
double rec(int x,int y,int z,int n)
{
    if(x + y + z == 0) return 0;
    if(memo[x][y][z]) return dp[x][y][z];
    double k = x + y + z;
    double ans = (double)n/k;
    if(z > 0) ans += ((double)z/k) * rec(x,y+1,z-1,n);
    if(y > 0) ans += ((double)y/k) * rec(x+1,y-1,z,n);
    if(x > 0) ans += ((double)x/k) * rec(x-1,y,z,n);
    memo[x][y][z] = true;
    return dp[x][y][z] = ans;
}
int main()
{
    int n;
    cin>>n;
    int x = 0,y = 0,z = 0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a == 1) x++;
        else if(a == 2) y++;
        else z++;
    }
    memset(memo,false,sizeof(memo));
    memset(dp,-1,sizeof(dp));
    double ans = rec(x,y,z,n);
    cout<<setprecision(10)<<ans<<endl;
}