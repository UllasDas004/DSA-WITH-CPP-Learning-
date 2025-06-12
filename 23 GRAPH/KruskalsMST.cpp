#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>& a,vector<int>& b)
{
    return a[2] < b[2];
}
int find(vector<int>& par,int n)
{
    if(n == par[n]) return par[n];
    return par[n] = find(par,par[n]);
}
void Union(vector<int>& par,vector<int>& rank,int a,int b)
{
    a = find(par,a);
    b = find(par,b);
    if(a == b) return;
    if(rank[a] >= rank[b])
    {
        par[b] = a;
        rank[a]++;
    }
    else
    {
        par[a] = b;
        rank[b]++;
    }
}
long long Kruskals(vector<vector<int>>& edges,int v,int e)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> par(v+1),rank(v+1,1);
    for(int i=0;i<v+1;i++) par[i] = i;
    int edgeCount = 0;
    int i=0;
    long long ans = 0;
    while(edgeCount < v-1 && i < e)
    {
        int src = find(par,edges[i][0]);
        int dst = find(par,edges[i][1]);
        int wt = edges[i][2];
        if(src != dst)
        {
            Union(par,rank,src,dst);
            ans += wt;
            edgeCount++;
        }
        i++;
    }
    return ans;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(e,vector<int>(3));
    for(int i=0;i<e;i++)
    cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    cout<<Kruskals(edges,v,e)<<endl;
    return 0;
}