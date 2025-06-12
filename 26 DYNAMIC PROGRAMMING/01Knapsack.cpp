#include<bits/stdc++.h>
using namespace std;
int helper(int c, vector<int> &val, vector<int> &wt,int idx,int w,vector<vector<int>>& dp)
{
    if(idx == val.size())  return 0;
    if(dp[idx][w] != -1) return dp[idx][w];
    if(w + wt[idx] > c) return dp[idx][w] = helper(c,val,wt,idx+1,w,dp);
    int take = val[idx] + helper(c,val,wt,idx+1,w+wt[idx],dp);
    int leave = helper(c,val,wt,idx+1,w,dp);
    return dp[idx][w] = max(take,leave);
}
int knapsack(int c, vector<int> &val, vector<int> &wt)
{
    // code here
    vector<vector<int>> dp(val.size(),vector<int>(c+1,-1));
    return helper(c,val,wt,0,0,dp);
}
int main()
{
    int n;
    cout<<"Enter number of items:- ";
    cin>>n;
    vector<int> items(n),value(n);
    cout<<"Enter weight of the items one by one and there corresponding values.\n";
    for(int i=0;i<n;i++) cin>>items[i]>>value[i];
    int capacity;
    cout<<"Enter the knapsack capacity:- ";
    cin>>capacity;
    cout<<"The max profit thief can get is "<<knapsack(capacity,value,items)<<endl;
}