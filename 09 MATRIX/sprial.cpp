#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the number of rows:- ";
    cin>>m;
    cout<<"Enter the number of columns:- ";
    cin>>n;
    int a[m][n];
    cout<<"Enter the matrix."<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    int minrow=0,mincol=0,maxrow=m,maxcol=n;
    int count = 0;
    cout<<"Spiral."<<endl;
    while(count<m*n)
    {
        for(int i=mincol;i<maxcol;i++,count++)
        cout<<a[minrow][i]<<" ";
        minrow++;
        if(count==m*n) break;
        for(int i=minrow;i<maxrow;i++,count++)
        cout<<a[i][maxcol-1]<<" ";
        maxcol--;
        if(count==m*n) break;
        for(int i=maxcol-1;i>=mincol;i--,count++)
        cout<<a[maxrow-1][i]<<" ";
        maxrow--;
        if(count==m*n) break;
        for(int i=maxrow-1;i>=minrow;i--,count++)
        cout<<a[i][mincol]<<" ";
        mincol++;
        if(count==m*n) break;
    }
    return 0;
}