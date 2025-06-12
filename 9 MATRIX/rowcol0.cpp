#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of rows:- ";
    cin>>n;
    int m;
    cout<<"Enter the number of columns:- ";
    cin>>m;
    int a[n][m];
    cout<<"Enter matrix."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    
    int ii=-1,jj=-1;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 0)
            {
                ii = i;
                jj = j;
                flag = true;
            }
        }
    }
    if(flag == true)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            a[j][jj] = 0;
            for(int j=0;j<m;j++)
            a[ii][j] = 0;
        }
    }
    cout<<"New matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}