#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<int>& arr,int i,int n)
{
    while(true)
    {
        int left = 2*i,right = 2*i+1;
        if(left>=n) break;
        if(right>=n)
        {
            if(arr[i] > arr[left])
            swap(arr[i],arr[left]);
            break;
        }
        if(arr[left] < arr[right])
        {
            if(arr[i] > arr[left])
            {
                swap(arr[i],arr[left]);
                i = left;
            }
            else break;
        }
        else
        {
            if(arr[i] > arr[right])
            {
                swap(arr[i],arr[right]);
                i = right;
            }
            else break;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n+1);   // 1-based indexing
    arr[0] = -1;
    cout<<"Enter the elements of the array: ";
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,i,n);
    }
    cout<<"The heapified array is: ";
    for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}