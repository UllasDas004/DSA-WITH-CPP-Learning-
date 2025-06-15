#include<iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2;
    cout<<"Enter the number of rows of first matrix:- ";
    cin>>r1;
    cout<<"Enter the number of columns of first matrix:- ";
    cin>>c1;
    cout<<"Enter the number of rows of second matrix:- ";
    cin>>r2;
    cout<<"Enter the number of columns of second matrix:- ";
    cin>>c2;
    if(c1 != r2) cout<<"Multiplication not possible.";
    else
    {
        int a[r1][c1],b[r2][c2];
        cout<<"Enter first matrix"<<endl;
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            cin>>a[i][j];
        }
        cout<<"Enter second matrix"<<endl;
        for(int i=0;i<r2;i++)
        {
            for(int j=0;j<c2;j++)
            cin>>b[i][j];
        }
        int p[r1][c2];
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                p[i][j] = 0;
                for(int k=0;k<r2;k++)
                p[i][j] += (a[i][k]*b[k][j]);
            }
        }
        cout<<"Product matrix"<<endl;
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            cout<<p[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}