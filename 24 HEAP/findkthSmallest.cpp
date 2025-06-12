#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter number of elements in array:- ";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"Enter the value of k:- ";
    cin>>k;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<"The "<<k<<"th smallest element is "<<pq.top()<<endl;
    return 0;
}