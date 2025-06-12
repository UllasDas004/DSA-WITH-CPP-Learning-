#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<pair<int,int>>> graph;
int v;
void addEdge(int src,int dest,int wt,bool biDir = true)
{
    graph[src].push_back({dest,wt});
    if (biDir) graph[dest].push_back({src,wt});
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(auto j=graph[i].begin();j!=graph[i].end();j++)
        cout<<"("<<j->first<<","<<j->second<<")->";
        cout<<"NULL"<<endl;
    }
}
int main()
{
    cout<<"Enter number of vertices:- ";
    cin>>v;
    graph.resize(v,list<pair<int,int>>());
    cout<<"Enter number of edges:- ";
    int e;
    cin>>e;
    while(e--)
    {
        int s,d,wt;
        cout<<"Enter source ,destination and weight:- ";
        cin>>s>>d>>wt;
        addEdge(s,d,wt);
    }
    display();
    return 0;
}