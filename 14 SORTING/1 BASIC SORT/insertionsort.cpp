#include<iostream>
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
    cout<<"Before sorting."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0 && a[j-1]>a[j];j--)
        swap(a[j-1],a[j]);
    }
    cout<<endl<<"After sorting."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}