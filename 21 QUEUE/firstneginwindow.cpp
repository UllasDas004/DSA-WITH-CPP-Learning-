#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the size of window:- ";
    cin>>k;
    int ans[n-k+1];
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        q.push(i);
    }
    for(int i=0;i<n-k+1;i++)
    {
        while(q.size() && q.front()<i) q.pop();
        if(q.size() && q.front()<i+k) ans[i] = arr[q.front()];
        else ans[i] = 0;
    }
    for(int i=0;i<n-k+1;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}