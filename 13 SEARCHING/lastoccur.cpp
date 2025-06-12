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
    int target;
    cout<<"Enter target element:- ";
    cin>>target;
    int lo = 0,hi = n-1;
    int idx = -1;
    bool flag = false;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(a[mid] == target)
        {
            if(a[mid+1] != target)
            {
                idx = mid;
                flag = true;
                break;
            }
            else lo = mid + 1;
        }
        else if(a[mid]<target) lo = mid + 1;
        else hi = mid - 1;
    }
    if(flag == false) cout<<"Target not found.";
    else cout<<"Target found at index "<<idx;
    return 0;
}