/*Problem Statement
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence 
a=(a1,a2,…,aN).Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of 
a. The player earns 
x points, where 
x is the removed element.
Let 
X and 
Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize 
X−Y, while Jiro tries to minimize 
X−Y.
Assuming that the two players play optimally, find the resulting value of 
X−Y.
Constraints
All values in input are integers.
1≤N≤3000
1≤ai≤10^9
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long f(vector<int>& v,int i,int j,vector<vector<long long>>& dp)
{
    if(i == j) return v[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(v[i] - f(v,i+1,j,dp),v[j] - f(v,i,j-1,dp));
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<long long>> dp(3005,vector<long long>(3005,-1));
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<f(v,0,n-1,dp);
    return 0;
}