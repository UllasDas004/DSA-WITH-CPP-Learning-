#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of row:- ";
    cin>>n;
    cout<<"Enter the number of columns:- ";
    cin>>m;
    int a[n][m];
    cout<<"Enter the matrix."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int max=INT_MIN,smax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]>max)
            {
                smax = max;
                max = a[i][j];
            }
            else if(smax<a[i][j] && max!=a[i][j]) smax = a[i][j];
        }
    }
    cout<<"Maximum element is "<<max<<endl;
    cout<<"Second maximum element is "<<smax;
    return 0;
}