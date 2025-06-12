#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int h(vector<int>& arr,int i,int j,vector<vector<int>>& dp)
{
    if(i == j || i+1 == j) return 0;
    int mn = INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    for(int k=i+1;k<=j-1;k++)
    {
        int left = h(arr,i,k,dp);
        int right = h(arr,k,j,dp);
        int mat = arr[i]*arr[j]*arr[k];
        mn = min({mn,(left+right+mat)});
    }
    return dp[i][j] = mn;
}
int main()
{
    int n;
    cin>>n;
    if(n <= 2) return 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> dp(n-2,vector<int>(n,-1));
    cout<<h(arr,0,n-1,dp)<<endl;
    vector<vector<int>> d(n-2,vector<int>(n,0));
    for(int len=3;len<=n;len++)
    {
        for(int i=0;i+len-1<n;i++)
        {
            int j = i+len-1;
            d[i][j] = INT_MAX;
            for(int k=i+1;k<=j-1;k++)
            {
                int left = d[i][k];
                int right = d[k][j];
                int mat = arr[i]*arr[j]*arr[k];
                d[i][j] = min({d[i][j],(left+right+mat)});
            }
        }
    }
    cout<<dp[n-3][n-1]<<endl;
    return 0;
}