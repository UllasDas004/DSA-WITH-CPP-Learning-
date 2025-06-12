#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
int v;
void addEdge(int src,int dest,bool biDir = true)
{
    graph[src].push_back(dest);
    if(biDir) graph[dest].push_back(src);
}
void dfs(int node,vector<bool>& visited)
{
    visited[node] = true;
    for(auto neighbor : graph[node])
    {
        if(!visited[neighbor])
        dfs(neighbor,visited);
    }
}
int connectedComponent(vector<bool>& visited)
{
    int count = 0;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i,visited);
        }
    }
    return count;
}
int main()
{
    cout<<"Enter number of vertices:- ";
    cin>>v;
    graph.resize(v,list<int>());
    cout<<"Enter number of edges:- ";
    int e;
    cin>>e;
    if (cin.fail() || e < 0) 
    {
        cout << "Invalid number of edges. Please enter a non-negative integer." << endl;
        return 1;
    }
    while(e--)
    {
        int s,d;
        cin>>s>>d;
        addEdge(s,d);
    }
    vector<bool> visited(v,false);
    cout<<"Number of connected components are:- "<<connectedComponent(visited)<<endl;
    return 0;
}