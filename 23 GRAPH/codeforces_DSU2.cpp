#include<bits/stdc++.h>
using namespace std;
vector<int> par,rnk;
vector<int> sz,maxi,mini;
int get(int n)
{
    if(n == par[n]) return par[n];
    return par[n] = get(par[n]);
}
void Union(int a,int b)
{
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(rnk[a] >= rnk[b])
    {
        par[b] = a;
        rnk[a]++;
        sz[a] += sz[b];
        maxi[a] = max(maxi[a],maxi[b]);
        mini[a] = min(mini[a],mini[b]);
    }
    else
    {
        par[a] = b;
        rnk[b]++;
        sz[b] += sz[a];
        maxi[b] = max(maxi[a],maxi[b]);
        mini[b] = min(mini[a],mini[b]);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    par.resize(n+1);
    rnk.resize(n+1,1);
    sz.resize(n+1,1);
    maxi.resize(n+1);
    mini.resize(n+1);
    for(int i=1;i<=n;i++) par[i] = mini[i] = maxi[i] = i;
    while(m--)
    {
        string s;
        cin>>s;
        if(s == "union")
        {
            int a,b;
            cin>>a>>b;
            Union(a,b);
        }
        if(s == "get")
        {
            int a;
            cin>>a;
            int b = get(a);
            cout<<mini[b]<<" "<<maxi[b]<<" "<<sz[b]<<endl;
        }
    }
    return 0;
}