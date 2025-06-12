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
    bool flag = false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            flag = true;
            if(a[j]>=a[j+1])
            {
                swap(a[j],a[j+1]);
                flag = false;
            }
        }
        if(flag == true) break;
    }
    cout<<endl<<"After sorting."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}