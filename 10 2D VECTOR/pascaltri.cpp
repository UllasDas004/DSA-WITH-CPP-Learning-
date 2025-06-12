#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of rows:- ";
    cin>>n;
    vector< vector<int> > v;
    for(int i=0;i<n;i++)
    {
        vector<int> a(i+1);
        v.push_back(a);
        for(int j=0;j<=i;j++)
        {
            if(i==j||j==0)
            v[i][j] = 1;
            else
            v[i][j] = v[i-1][j-1]+v[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}