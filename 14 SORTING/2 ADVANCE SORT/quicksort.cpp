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
    int i = si,j = ei;
    int pi = count + si;
    swap(v[(si+ei)/2],v[pi]);
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
void quicksort(vector<int>& v,int si,int ei)
{
    if(si>=ei) return;
    int pi = partition(v,si,ei);
    quicksort(v,si,pi-1);
    quicksort(v,pi+1,ei);
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
    cout<<"Before sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    cout<<endl;
    quicksort(v,0,n-1);
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;
}