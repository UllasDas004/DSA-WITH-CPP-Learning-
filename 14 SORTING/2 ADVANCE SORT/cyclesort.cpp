#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[] = {1,4,2,5,3};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Before sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    int i=0;
    while(i<n)
    {
        int correctIdx = a[i] - 1;
        if(i == correctIdx) i++;
        else swap(a[i],a[correctIdx]);
    }
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}