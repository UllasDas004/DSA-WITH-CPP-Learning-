#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int k;
    cout<<"Enter k:- ";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]<a[j+1])
            swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<a[n-k];
    return 0;
}