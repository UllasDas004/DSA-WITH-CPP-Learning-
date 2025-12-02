/*
Problem similar to 0/1 Knapsack but the catch is
I can take at most k consecutive items
*/

#include<bits/stdc++.h>
using namespace std;
int dp[105][10100][105];
int rec(vector<int>& items,vector<int>& values,int level,int sum,int w,int currK,int k)
{
    if(level == items.size()) return 0;
    if(dp[level][sum][currK] != -1) return dp[level][sum][currK];
    int ans = rec(items,values,level+1,sum,w,0,k);
    if(sum+items[level] <= w && currK < k)
    ans = max(ans,values[level] + rec(items,values,level+1,sum+items[level],w,currK+1,k));
    return dp[level][sum][currK] = ans;
}
int main()
{
    int n;
    cout<<"Enter number of items:- ";
    cin>>n;
    vector<int> items(n),value(n);
    cout<<"Enter weight of the items one by one and there corresponding values.\n";
    for(int i=0;i<n;i++) cin>>items[i]>>value[i];
    int capacity,k;
    cout<<"Enter the knapsack capacity:- ";
    cin>>capacity;
    cout<<"Enter the consecutive item cap:- ";
    cin>>k;
    memset(dp,-1,sizeof(dp));
    int ans = rec(items,value,0,0,capacity,0,k);
    cout<<"The max profit thief can get is "<<ans<<endl;
}