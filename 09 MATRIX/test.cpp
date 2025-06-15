#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> v(2,vector<int>(3));
    v[0] = {1,7,20};
    v[1] = {2,6,10};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<2;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}