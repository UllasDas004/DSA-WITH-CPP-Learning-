#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
double dp[105][105][105];
double fr(int r,int s,int p)
{
    if(p == 0) return 1;
    if(r == 0 || s == 0) return 0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    double total = r*s + s*p + p*r;
    double rs = fr(r,s-1,p)*(r*s)/total;
    double pr = fr(r-1,s,p)*(p*r)/total;
    double sp = fr(r,s,p-1)*(s*p)/total;
    return dp[r][s][p] = rs+pr+sp;
}
double fs(int r,int s,int p)
{
    if(r == 0) return 1;
    if(s == 0 || p == 0) return 0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    double total = r*s + s*p + p*r;
    double rs = fs(r,s-1,p)*(r*s)/total;
    double pr = fs(r-1,s,p)*(p*r)/total;
    double sp = fs(r,s,p-1)*(s*p)/total;
    return dp[r][s][p] = rs+pr+sp;
}
double fp(int r,int s,int p)
{
    if(s == 0) return 1;
    if(p == 0 || r == 0) return 0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    double total = r*s + s*p + p*r;
    double rs = fp(r,s-1,p)*(r*s)/total;
    double pr = fp(r-1,s,p)*(p*r)/total;
    double sp = fp(r,s,p-1)*(s*p)/total;
    return dp[r][s][p] = rs+pr+sp;
}
int main()
{
    int r,s,p;
    cin>>r>>s>>p;
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<fr(r,s,p)<<" ";
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<fs(r,s,p)<<" ";
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<fp(r,s,p)<<endl;
    return 0;
}