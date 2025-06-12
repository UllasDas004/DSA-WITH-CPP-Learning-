#include<iostream>
#include<algorithm>
#include<climits>
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
    for(int i=0;i<n-1;i++)
    {
        int min = INT_MAX;
        int minidx = -1;
        for(int j=i;j<n;j++)
        {
            if(a[j]<min)
            {
                min = a[j];
                minidx = j;
            }
        }
        swap(a[minidx],a[i]);

    }
    cout<<endl<<"After sorting."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}