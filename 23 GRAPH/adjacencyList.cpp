#include<iostream>
#include<vector>
#include<list>
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
    display();
    return 0;
}