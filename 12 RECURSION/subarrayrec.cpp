#include<iostream>
#include<vector>
using namespace std;
void subarray(vector<int> ans,int arr[],int n,int idx)
{
    if(idx == n)
    {
        for(int i=0;i<ans.size();i++)
        cout<<ans[i];
        cout<<endl;
        return;
    }
    subarray(ans,arr,n,idx+1);
    if(ans.size() == 0 || ans[ans.size()-1] == arr[idx-1])
    {
        ans.push_back(arr[idx]);
        subarray(ans,arr,n,idx+1);
    }
    return;
}
int main()
{
    int n;
    cout<<"Enter the size:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    vector<int> v;
    cout<<"All subarrays."<<endl;
    subarray(v,a,n,0);
    return 0;
}