#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter a non negative number:- ";
    cin>>x;
    int lo = 0,hi = x;
    int ans = -1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(mid*mid == x)
        {
            ans = mid;
            break;
        }
        else if(mid*mid<x) lo = mid + 1;
        else hi = mid - 1;
    }
    if(ans == -1) cout<<"There is no integer square root of "<<x;
    else cout<<"Square root of "<<x<<" is "<<ans;
    return 0;
}