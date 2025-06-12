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
    int k;
    cout<<"Enter the size of subarrays:- ";
    cin>>k;
    int maxsum,maxidx = 0;
    int sum = 0;
    for(int i=0;i<k;i++) sum += a[i];
    // SLIDING WINDOW ALGORITHM
    maxsum = sum;
    for(int i=1,j=k;j<n;i++,j++)
    {
        sum = sum + a[j] - a[i-1];
        if(maxsum<sum)
        {
            maxsum = sum;
            maxidx = i;
        }
    }
    cout<<"Maximum possible subarrays is"<<endl<<"[ ";
    for(int i=maxidx;i<maxidx+k;i++)
    cout<<a[i]<<" ";
    cout<<"]"<<endl<<"Maximum sum is "<<maxsum;
    return 0;
}