#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cstring>
#define ll long long int
using namespace std;
int r,c;
ll dp[105][105][105];
char v[105][105];
ll f(int i,int j,int x,int y)
{
    if(i>r || j>c || x>r || y>c || v[i][j] == '#' || v[x][y] == '#') return 0;
    if(i == r && j == c)
    return (v[i][j] == '*');
    if(dp[i][j][x] != -1) return dp[i][j][x];
    ll result = INT_MIN;
    result = max(result,f(i+1,j,x+1,y));
    result = max(result,f(i,j+1,x+1,y));
    result = max(result,f(i+1,j,x,y+1));
    result = max(result,f(i,j+1,x,y+1));
    result += (v[i][j] == '*');
    result += (v[x][y] == '*');
    if(i == x && j == y && v[i][j] == '*') result--;
    return dp[i][j][x] = result;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>c>>r;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            cin>>v[i][j];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(1,1,1,1)<<endl;
    }
    return 0;
}