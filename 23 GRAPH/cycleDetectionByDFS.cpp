#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int v;
void addEdge(int src,int dest,bool biDir = true)
{
    graph[src].push_back(dest);
    if (biDir) graph[dest].push_back(src);
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(auto j=graph[i].begin();j!=graph[i].end();j++)
        cout<<*j<<"->";
        cout<<"NULL"<<endl;
    }
}
bool hasCycle(int src,int par,unordered_set<int>& visited)
{
    visited.insert(src);
    for(auto neighbour : graph[src])
    {
        if(visited.find(neighbour) != visited.end() && neighbour != par)
        return true;
        if(visited.find(neighbour) == visited.end())
        {
            if(hasCycle(neighbour,src,visited))
            return true;
        }
    }
    return false;
}
int main()
{
    cout<<"Enter number of vertices:- ";
    cin>>v;
    graph.resize(v,list<int>());
    cout<<"Enter number of edges:- ";
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        addEdge(s,d);
    }
    unordered_set<int> visited;
    bool flag = false;
    for(int i=0;i<v;i++)
    {
        if(visited.find(i) == visited.end())
        {
            flag = hasCycle(i,-1,visited);
            if(flag) break;
        }
    }
    display();
    if(flag) cout<<"There exists a cycle in the graph!"<<endl;
    else cout<<"There is no cycle in the graph!"<<endl;
    return 0;
}