// There is a n*m grid with each cell having certain values
// have to find the path form (0,0) to (n-1,m-1) which has the maximum sum
// only right and down moves are allowed

#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int rec(vector<vector<int>>& grid,int r,int c)
{
    if(r < 0 || c < 0) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    int up = rec(grid,r-1,c);
    int left = rec(grid,r,c-1);
    return dp[r][c] = grid[r][c] + max(up,left);
}

int main()
{
    int n,m;
    cout<<"Enter the rows and columns:- ";
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    cout<<"Enter the values :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>grid[i][j];
    }
    memset(dp,-1,sizeof(dp));
    int ans = rec(grid,n-1,m-1);
    cout<<ans<<endl;
}