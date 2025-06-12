#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
long long g(vector<int>& v,int i,int j)
{
    long long result = 0;
    for(int m=i;m<=j;m++)
    {
        result += v[m];
        result %= 100;
    }
    return result;
}
long long h(vector<int>& v,int i,int j,vector<vector<long long>>& dp)
{
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long mn = INT_MAX;
    for(int k=i;k<j;k++)
    {
        long long left = h(v,i,k,dp);
        long long right = h(v,k+1,j,dp);
        long long result = g(v,i,k)*g(v,k+1,j);
        mn = min(mn,left+right+result);
    }
    return dp[i][j] = mn;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<long long>> dp(105,vector<long long>(105,-1));
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        cout<<h(v,0,n-1,dp)<<endl;
        v.clear();
    }
}