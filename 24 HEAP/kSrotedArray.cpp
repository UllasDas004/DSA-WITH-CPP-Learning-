#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<":- ";
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k:- ";
    cin>>k;
    cout<<"The original array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int idx = 0;
    for(int i=0; i<n; i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size() > k)
        {
            arr[idx++] = minHeap.top();
            minHeap.pop();
        }
    }
    while(minHeap.size())
    {
        arr[idx++] = minHeap.top();
        minHeap.pop();
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}