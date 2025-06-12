#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++) pq.push(arr[i]);
    for(int i=0;i<n;i++)
    {
        arr[i] = pq.top();
        pq.pop();
    }
    cout<<"Sorted array is\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}