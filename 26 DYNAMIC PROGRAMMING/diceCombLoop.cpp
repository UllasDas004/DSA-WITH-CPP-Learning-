#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int h(int n)
{
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    for(int k=1;k<=n;k++)
    {
        int sum = 0;
        for(int i=1;i<=6;i++)
        {
            if(k-i<0) break;
            sum += dp[k-i];
            sum %= 1000000007;
        }
        dp[k] = sum;
    }
    return dp[n]%1000000007;
}
int main()
{
    int n;
    cin>>n;
    cout<<h(n);
    return 0;
}