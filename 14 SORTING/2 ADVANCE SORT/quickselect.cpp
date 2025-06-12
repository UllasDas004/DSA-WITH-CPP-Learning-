#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int>& v,int si,int ei)
{
    int pivotElement = v[(si+ei)/2];
    int count = 0;
    for(int i=si;i<=ei;i++)
    {
        if(i == (si+ei)/2) continue;
        if(v[i]<=pivotElement)
        count++;
    }
    int pi = si + count;
    swap(v[(si+ei)/2],v[pi]);
    int i = si,j = ei;
    while(i<pi && j>pi)
    {
        if(v[i]<=pivotElement) i++;
        if(v[j]>pivotElement) j--;
        else if(v[i]>pivotElement && v[j]<=pivotElement)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    return pi;
}
int kthSmallest(vector<int>& v,int si,int ei,int k)
{
    int pi = partition(v,si,ei);
    if(pi+1 == k) return v[pi];
    else if(pi+1 < k) return kthSmallest(v,pi+1,ei,k);
    else if(pi+1 > k) return kthSmallest(v,si,pi-1,k);
}
int kthLargest(vector<int>& v,int si,int ei,int k)
{
    int pi = partition(v,si,ei);
    int n = v.size();
    if(pi+1 == n-k+1) return v[pi];
    else if(pi+1 < n-k+1) return kthLargest(v,pi+1,ei,k);
    else if(pi+1 > n-k+1) return kthLargest(v,si,pi-1,k);
}
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element"<<i+1<<":- ";
        cin>>v[i];
    }
    cout<<"Enter k:- ";
    int k;
    cin>>k;
    cout<<"kth smallest element is "<<kthSmallest(v,0,n-1,k)<<endl;
    cout<<"kth largest element is "<<kthLargest(v,0,n-1,k);
    return 0;
}