#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
int v;
vector<bool> visited;
vector<vector<int>> result;
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
bool anyPath(int curr,int end)
{
    if(curr == end) return true;
    if(visited[curr]) return false;
    visited[curr] = true;
    for(auto neighbour:graph[curr])
    {
        if(!visited[neighbour])
        {
            bool result = anyPath(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}
void allPath(int curr,int end,vector<int>& path)
{
    if(curr == end)
    {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited[curr] = true;
    path.push_back(curr);
    for(auto neighbour:graph[curr])
    {
        if(!visited[neighbour])
        allPath(neighbour,end,path);
    }
    path.pop_back();
    visited[curr] = false;
    return;
}
int main()
{
    cout<<"Enter number of vertices:- ";
    cin>>v;
    graph.resize(v,list<int>());
    visited.clear();
    visited.resize(v,false);
    cout<<"Enter number of edges:- ";
    int e;
    cin>>e;
    while(e--)
    {
        int s,d;
        cin>>s>>d;
        addEdge(s,d);
    }
    int x,y;
    cout<<"Enter source and destination:- ";
    cin>>x>>y;
    result.clear();
    vector<int> path;
    allPath(x, y, path);
    cout<<"All paths from "<<x<<" to "<<y<<endl;
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        cout<<result[i][j]<<"->";
        cout<<"NULL"<<endl;
    }
    if(anyPath(x,y)) cout<<"Path exists from "<<x<<" to "<<y<<endl;
    else cout<<"Path does not exists from "<<x<<" to "<<y<<endl;
    //display();
    return 0;
}