/*
there are n integers and a target sum
check if there exists any subset that sum equal to target
*/


#include<bits/stdc++.h>
using namespace std;
int dp[101][10005];
bool rec(vector<int>& a,int level,int sum,int t)
{
    // base case
    if(level == a.size())
    {
        if(sum == t) return true;
        else return false;
    }
    //cache check
    if(dp[level][sum] != -1) return dp[level][sum];
    // transition
    bool ans = rec(a,level+1,sum,t);
    if(sum+a[level] <= t) ans |= rec(a,level+1,sum+a[level],t);
    return dp[level][sum] = ans;
}
int main()
{
    int n,t;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements with spaces :\n";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter the target sum:- ";
    cin>>t;
    memset(dp,-1,sizeof(dp));
    bool ans = rec(a,0,0,t);
    if(ans) cout<<"Yes possible."<<endl;
    else cout<<"No not possible."<<endl;
    return 0;
}