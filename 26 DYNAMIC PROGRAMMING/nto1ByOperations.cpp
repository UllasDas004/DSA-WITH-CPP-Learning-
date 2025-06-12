#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minStepsRec(int n,vector<int>& dp)
{
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(dp[n] != 1) return dp[n];
    int x = minStepsRec(n-1,dp);
    int y = INT_MAX,z = INT_MAX;
    if(n%2 == 0) y = minStepsRec(n/2,dp);
    if(n%3 == 0) z = minStepsRec(n/3,dp);
    return dp[n] += min(x,min(y,z));
}
int minSteps(int n)
{
    vector<int> d(n+1,-1);
    d[1] = 0;
    d[2] = d[3] = 1;
    for(int i=4;i<=n;i++)
    {
        int x = d[i-1];
        int y = INT_MAX,z = INT_MAX;
        if(i%2 == 0) y = d[i/2];
        if(i%3 == 0) z = d[i/3];
        d[i] = 1 + min(x,min(y,z));
    }
    return d[n];
}
int main()
{
    int n;
    cout<<"Enter n:- ";
    cin>>n;
    vector<int> dp(n+1,1);
    cout<<"Minimum steps required is "<<minStepsRec(n,dp)<<endl;
    cout<<"Minimum steps required is "<<minSteps(n)<<endl;
    return 0;
}