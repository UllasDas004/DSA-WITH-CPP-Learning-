#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"Original array."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    int prefix[n];
    prefix[0] = a[0];
    for(int i=1;i<n;i++)
    prefix[i] = prefix[i-1] + a[i];
    cout<<"Prefix array."<<endl;
    for(int i=0;i<n;i++)
    cout<<prefix[i]<<" ";
    return 0;
}