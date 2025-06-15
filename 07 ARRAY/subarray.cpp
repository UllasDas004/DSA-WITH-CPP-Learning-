#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"All subarrays."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            cout<<a[k];
            cout<<endl;
        }
    }
    return 0;
}