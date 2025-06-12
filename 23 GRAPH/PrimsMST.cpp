#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp>> graph;
void addEdge(int u,int v,int wt,bool biDir = true)
{
    graph[u].push_back({v,wt});
    if(biDir) graph[v].push_back({u,wt});
}
long long Prims(int src,int v)
{
    priority_queue<pp,vector<pp>,greater<pp>> minHeap;
    unordered_set<int> visited;
    vector<int> par(v);
    minHeap.push({0,src});
    unordered_map<int,int> mp;
    for(int i=0;i<v;i++) mp[i] = INT_MAX;
    mp[src] = 0;
    int edgeCount = 0;
    ll ans = 0;
    while(edgeCount < v-1 && minHeap.size())
    {
        pp curr = minHeap.top();
        minHeap.pop();
        if(visited.find(curr.second) != visited.end()) continue;
        visited.insert(curr.second);
        ans += curr.first;
        edgeCount++;
        for(auto neighbour : graph[curr.second])
        {
            if(visited.find(neighbour.first) == visited.end() && mp[neighbour.first] > neighbour.second)
            {
                mp[neighbour.first] = neighbour.second;
                minHeap.push({neighbour.second,neighbour.first});
                par[neighbour.first] = curr.second;
            }
        }
    }
    return ans;
}
int main()
{
    int v,e;
    cin>>v>>e;
    v++;
    graph.resize(v,list<pp> ());
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<Prims(src,v)<<endl;
    return 0;
}