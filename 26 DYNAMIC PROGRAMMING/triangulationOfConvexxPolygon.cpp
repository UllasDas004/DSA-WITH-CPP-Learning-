/*
There is given coordinates of points (x,y) in clockwise manner which forms a convex polygon
we have to decide the minimum cost to triangulate
meaning we have to add diagonals to separate it into triangles
cost of adding a diagonal is sin(length of the diagonal)
*/


#include<bits/stdc++.h>
using namespace std;
double cost(vector<double> a,vector<double> b)
{
    double dist = sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    return sin(dist);
}
int main()
{
    int n;
    cout<<"Enter the number of points:- ";
    cin>>n;
    vector<vector<double>> points(n+1,vector<double>(2));
    cout<<"Enter the coordinates of the points clockwise manner:\n";
    for(int i=1;i<=n;i++) cin>>points[i][0]>>points[i][1];
    vector<vector<double>> dp(n+1,vector<double>(n+1));
    for(int len=3;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r = l + len - 1;
            // dp[l][r] = ?
            if(len == 3)
            {
                dp[l][r] = 0;
                continue;
            }
            double ans = 1e9;
            for(int x=l+1;x<=r-1;x++)
            {
                if(x == l+1) // only single new polygon forms
                ans = min(ans,cost(points[l+1],points[r])+dp[l+1][r]);
                else if(x == r-1) // only single new polygon forms
                ans = min(ans,cost(points[l],points[r-1])+dp[l][r-1]);
                else //two new polygons forms
                ans = min(ans,cost(points[l],points[x])+cost(points[x],points[r])+dp[l][x]+dp[x][r]);
            }
            dp[l][r] = ans;
        }
    }
    cout<<"Minimum cost to triangulate the convex polygon is "<<dp[1][n]<<endl;
}