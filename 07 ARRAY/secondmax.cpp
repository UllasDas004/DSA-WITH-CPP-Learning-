#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int max = a[0];
    for(int i=0;i<=n-1;i++)
    {
        if(a[i]>max) max = a[i];
    }
    int smax = INT_MIN;
    for(int i=0;i<=n-1;i++)
    {
        if(a[i]>smax && a[i]!=max)
        smax = a[i];
    }
    cout<<"Second maximum element is "<<smax;
    return 0;
}