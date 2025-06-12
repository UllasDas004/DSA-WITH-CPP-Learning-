#include<iostream>
#include<climits>
using namespace std;
int maxinarray(int arr[],int n,int idx)
{
    if(idx == n) return INT_MIN;
    return max(arr[idx],maxinarray(arr,n,idx+1));
}
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
    cout<<"Max element is "<<maxinarray(a,n,0);
    return 0;
}