#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int k,l,m;
    cin>>k>>l>>m;
    vector<int> v(m);
    for(int i=0;i<m;i++)
    cin>>v[i];
    vector<bool> dp(10000005,false);
    dp[1] = dp[k] = dp[l] = 1;
    for(int i=2;i<=dp.size();i++)
    {
        if(i==k || i==l) continue;
        bool kk = 1,ll = 1;
        if(i-k>1) kk = dp[i-k];
        if(i-l>1) ll = dp[i-l];
        dp[i] = !(dp[i-1] && kk && ll); 
    }
    for(int i=0;i<m;i++)
    {
        if(dp[v[i]] == true) cout<<"A";
        else cout<<"B";
    }
    return 0;
}