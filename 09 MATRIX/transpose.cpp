#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the order of matrix:- ";
    cin>>n;
    int a[n][n];
    cout<<"Enter the matrix."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    cout<<"Transpose of matrix."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}