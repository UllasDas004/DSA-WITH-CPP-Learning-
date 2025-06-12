#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>>& grid,int i,int j,int n)
{
    return (i>=0 && j>=0 && i<n && j<n && grid[i][j] == -1);
}
vector<int> dx {1,2,-1,-2,1,2,-1,-2};
vector<int> dy {2,1,2,1,-2,-1,-2,-1};
void knightsTour(vector<vector<int>>& grid,int i,int j,int n,int count)
{
    if(count == n*n)
    {
        grid[i][j] = count;
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            cout<<grid[x][y]<<" ";
            cout<<endl;
        }
        cout<<endl;
        grid[i][j] = -1;
        return;
    }
    for(int k=0;k<8;k++)
    {
        if(isSafe(grid,i+dx[k],j+dy[k],n))
        {
            grid[i][j] = count;
            knightsTour(grid,i+dx[k],j+dy[k],n,count+1);
            grid[i][j] = -1;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the size of board:- ";
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,-1)); // -1 denotes cell is vacant
    knightsTour(grid,0,0,n,1);
    return 0;
}