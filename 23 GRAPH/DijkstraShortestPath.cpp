#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector<list<pp>> graph;
vector<int> via;
void addEdge(int u,int v,int wt,bool biDir = true)
{
    graph[u].push_back({v,wt});
    if(biDir) graph[v].push_back({u,wt});
}
unordered_map<int,int> Dijkstra(int src,int v)
{
    priority_queue<pp,vector<pp>,greater<pp>> minHeap;
    unordered_map<int,int> mp;
    unordered_set<int> visited;
    via.resize(v);
    for(int i=0;i<v;i++) mp[i] = INT_MAX;
    mp[src] = 0;
    minHeap.push({0,src});
    while(minHeap.size())
    {
        pp curr = minHeap.top();
        minHeap.pop();
        if(visited.find(curr.second) != visited.end()) continue;
        visited.insert(curr.second);
        for(auto neighbour : graph[curr.second])
        {
            if(visited.find(neighbour.first) == visited.end() && mp[neighbour.first] > mp[curr.second] + neighbour.second)
            {
                minHeap.push({neighbour.second + mp[curr.second],neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second + mp[curr.second];
            }
        }
    }
    return mp;
}
int main()
{
    int v,e;
    cin>>v>>e;
    graph.resize(v,list<pp> ());
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src,dest;
    cin>>src>>dest;
    unordered_map<int,int> mp = Dijkstra(src,v);
    cout<<mp[dest]<<endl;
    for(auto p : mp)
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}