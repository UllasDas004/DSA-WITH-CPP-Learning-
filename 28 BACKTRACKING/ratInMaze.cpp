#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int ans;
bool canGo(vector<vector<int>>& maze,int n,int m,int i,int j)
{
    return (i>=0 && j>=0 && i<n && j<m && maze[i][j] == 0);
}
void f(vector<vector<int>>& maze,int i,int j,int n,int m)
{
    if(i == n-1 && j == m-1)
    {
        ans += 1;
        return;
    }
    maze[i][j] = 2;     // 2 means visited
    //left
    if(canGo(maze,n,m,i,j-1))
    f(maze,i,j-1,n,m);
    // up
    if(canGo(maze,n,m,i-1,j))
    f(maze,i-1,j,n,m);
    //right
    if(canGo(maze,n,m,i,j+1))
    f(maze,i,j+1,n,m);
    // down
    if(canGo(maze,n,m,i+1,j))
    f(maze,i+1,j,n,m);
    maze[i][j] = 0; // revert
}
int main()
{
    int n,m;
    cout<<"Enter height of the maze:- ";
    cin>>n;
    cout<<"Enter width of the maze:- ";
    cin>>m;
    vector<vector<int>> maze(n,vector<int>(n));
    cout<<"Enter the maze(row wise)."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>maze[i][j];
    }
    ans = 0;
    f(maze,0,0,n,m);
    cout<<"Number of paths = "<<ans<<endl;
    return 0;
}