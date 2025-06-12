#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s,t;
    cout<<"Enter first string:- ";
    getline(cin,s);
    cout<<"Enter second string:- ";
    getline(cin,t);
    int ns = s.length(),nt = t.length();
    vector<vector<int>> dp(ns+1,vector<int>(nt+1,0));
    int mx = 0;
    for(int i=1;i<=ns;i++)
    {
        for(int j=1;j<=nt;j++)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
            mx = max(mx,dp[i][j]);
        }
    }
    int x = ns,y = nt;
    string lcs = "";
    while(x>0 && y>0)
    {
        if(s[x-1] == t[y-1]) lcs = s[x-1] + lcs;
        if(dp[x-1][y] > dp[x][y-1]) x--;
        else y--;
    }
    cout<<"The longest common substring is "<<lcs<<endl;
    cout<<"The length of longest common substring is "<<mx<<endl<<"  ";
    for(int i=0;i<nt;i++) cout<<t[i]<<" ";
    cout<<endl;
    for(int i=1;i<=ns;i++)
    {
        cout<<s[i-1]<<" ";
        for(int j=1;j<=nt;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}