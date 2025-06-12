#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& par,int n)
{
    if(n == par[n]) return par[n];
    return par[n] = find(par,par[n]);
}
bool Union(vector<int>& par,vector<int>& rank,int a,int b)
{
    a = find(par,a);
    b = find(par,b);
    if(a == b) return true;
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
    return false;
}
int main()
{
    int v,e;
    cout<<"Enter the number of vertices:- ";
    cin>>v;
    cout<<"Enter the number of edges:- ";
    cin>>e;
    vector<vector<int>> edgeList(e,vector<int>(2));
    cout<<"Enter the edge vertices.\n";
    for(int i=0;i<e;i++)
    cin>>edgeList[i][0]>>edgeList[i][1];
    vector<int> par(v),rank(v,1);
    for(int i=0;i<v;i++) par[i] = i;
    bool isCyclic = false;
    for(int i=0;i<e;i++)
    {
        isCyclic = Union(par,rank,edgeList[i][0],edgeList[i][1]);
        if(isCyclic) break;
    }
    if(isCyclic) cout<<"Ther exists a cycle in the graph!"<<endl;
    else cout<<"Ther is no cycle in the graph!"<<endl;
    return 0;
}