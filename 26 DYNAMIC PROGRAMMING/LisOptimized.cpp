#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements with spaces :\n";
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> lis,insertedAt(n);
    for(int i=0;i<n;i++)
    {
        if(lis.empty() || lis.back() < a[i])
        {
            lis.push_back(a[i]);
            insertedAt[i] = lis.size();
        }
        else
        {
            auto it = lower_bound(lis.begin(),lis.end(),a[i]);
            *it = a[i];
            insertedAt[i] = it - lis.begin() + 1;
        }
    }
    cout<<"The length of longest common subsequence is "<<lis.size()<<endl;
    int currLen = lis.size();
    for(int i=n-1;i>=0;i--)
    {
        if(insertedAt[i] == currLen)
        {
            currLen--;
            lis[currLen] = a[i];
        }
    }
    for(int i=0;i<lis.size();i++) cout<<lis[i]<<" ";
    cout<<endl;
}