#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> l(n+1,0),r(n+1,0),f(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int ll,rr;
        cin>>ll>>rr;
        l[ll]++;
        r[rr]++;
    }
    f[1] = l[1];
    for(int i=2;i<=n;i++)
    f[i] = l[i] - r[i-1] + f[i-1];
    vector<int> c(1000005,0);
    for(int i=1;i<=n;i++)
    c[f[i]]++;
    for(int i=c.size()-1;i>=1;i--)
    c[i] += c[i+1];
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int qq;
        cin>>qq;
        cout<<c[qq]<<endl;
    }
    return 0;
}