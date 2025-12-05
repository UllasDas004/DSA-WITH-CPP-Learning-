/*
There are n chips
one can take y  chips in one move where y is any power of 2 means 2^m where m E (0,inf)
anyone could not make a move loses at any time
decide whether the first one to make the move wins or loses
*/

#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int rec(int n)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = 0; // assuming it is in losing state
    for(int m=0;(1<<m)<=n;m++)
    {
        if(n - (1<<m) == 0) // this moves leads to other player losing
        {
            ans = 1; // as soon as current player wins break it
            break;
        }
    }
    return dp[n] = ans;
}
int main()
{
    int n;
    cout<<"Enter the number of chips:- ";
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans = rec(n);
    if(ans == 1) cout<<"Wins"<<endl;
    else cout<<"Loses"<<endl;
    return 0;
}