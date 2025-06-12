#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array:- ";
    cin>>n;
    int a[n];
    cout<<"Enter in ascending number."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int lo = 0,hi = n-1;
    int idx = -1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(a[mid] == mid) lo = mid + 1;
        else
        {
            idx = mid;
            hi = mid - 1;
        }
    }
    if(idx == -1) cout<<"No missing element";
    else cout<<"Missing element is "<<idx;
    return 0;
}