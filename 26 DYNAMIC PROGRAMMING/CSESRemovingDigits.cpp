#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int h(int n,vector<int>& dp)
{
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    int steps = INT_MAX;
    int a = n;
    while(a>0)
    {
        if(a%10 != 0)
        steps = min(steps,h(n-(a%10),dp));
        a /= 10;
    }
    return dp[n] = 1 + steps;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<h(n,dp)<<endl;
    return 0;
}