// There are two piles of stones 
// one with A stones and other with B
// a player can choose two operations
// he can take any number of stones from any piles 
// or he can take any number of stones from both piles given that number should be equal for both piles


#include<bits/stdc++.h>
using namespace std;
// int dp[1001][1001];
// int rec(int a,int b)
// {
//     if(a == 0 && b == 0) return false;
//     if(dp[a][b] != -1) return dp[a][b];
//     int ans = 0;
//     for(int c=1;c<=a;c++)
//     {
//         if(rec(a-c,b) == 0)
//         {
//             ans = 1;
//             break;
//         }
//     }
//     for(int c=1;c<=b;c++)
//     {
//         if(rec(a,b-c) == 0)
//         {
//             ans = 1;
//             break;
//         }
//     }
//     for(int c=1;c<=min(a,b);c++)
//     {
//         if(rec(a-c,b-c) == 0)
//         {
//             ans = 1;
//             break;
//         }
//     }
//     return dp[a][b] = ans;
// }
int main()
{
    int a,b;
    cin>>a>>b;
    // memset(dp,-1,sizeof(dp));
    vector<vector<int>> dp(a+1,vector<int>(b+1,1));
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            int ans = 0;
            for(int k=1;k<=i;k++)
            {
                if(dp[i-k][j] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            for(int k=1;k<=j;k++)
            {
                if(dp[i][j-k] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            for(int k=1;k<=min(i,j);k++)
            {
                if(dp[i-k][j-k] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            dp[i][j] = ans;
        }
    }
    if(dp[a][b] == 1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}