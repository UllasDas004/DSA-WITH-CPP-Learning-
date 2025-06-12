#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>nums[i];
    }
    cout<<"Original array."<<endl;
    for(int i=0;i<n;i++)
    cout<<nums[i]<<" ";
    cout<<endl;
    vector<int> pre(n);
    int p = nums[0];
    pre[0] = 1;
    for(int i=1;i<n;i++)
    {
        pre[i] = p;
        p *= nums[i];
    }
    p = nums[n-1];
    for(int i=n-2;i>=0;i--)        
    {
        pre[i] *= p;
        p *= nums[i];
    }
    cout<<endl<<"Answer array."<<endl;
    for(int i=0;i<n;i++)
    cout<<pre[i]<<" ";
    return 0;
}