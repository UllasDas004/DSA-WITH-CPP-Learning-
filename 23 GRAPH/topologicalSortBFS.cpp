#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
vector<int> topological;
void addEdge(int a,int b,bool biDir = true)
{
    graph[a].push_back(b);
    if(biDir) graph[b].push_back(a);
}
void topologicalBFS()
{
    vector<int> inDegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto neighbour : graph[i])
        inDegree[neighbour]++;
    }
    queue<int> q;
    unordered_set<int> visited;
    for(int i=0;i<v;i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
            visited.insert(i);
        }
    }
    while(q.size())
    {
        int curr = q.front();
        topological.push_back(curr);
        q.pop();
        for(auto neighbour : graph[curr])
        {
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0)
            {
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}
int main()
{
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        addEdge(x,y,false);
    }
    topologicalBFS();
    if(topological.size() < v)
    {
        cout<<"The graph is not a directed acyclic graph!"<<endl;
        return 0;
    }
    for(int i=0;i<v;i++)
    cout<<topological[i]<<" ";
    cout<<endl;
    return 0;
}