#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;
vector<list<int>> graph;
int v;
vector<bool> visited;
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
void shortestPath(int src,vector<int>& dist)
{
    queue<int> q;
    visited[src] = true;
    dist.resize(v,INT_MAX);
    dist[src] = 0;
    q.push(src);
    while(q.size())
    {
        int curr = q.front();
        q.pop();
        for(auto neighbour:graph[curr])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}
int main()
{
    cout<<"Enter number of vertices:- ";
    cin>>v;
    graph.resize(v,list<int>());
    visited.resize(v,false);
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
    //display();
    vector<int> dist;
    int x,y;
    cout<<"Enter source and destination:- ";
    cin>>x>>y;
    shortestPath(x,dist);
    cout<<"Shortest path from "<<x<<" to "<<y<<" is "<<dist[y]<<endl;
    for(int i=0;i<v;i++) cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}