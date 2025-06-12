#include<iostream>
#include<vector>
using namespace std;
void subsequence(int arr[],int n,int idx,vector<int> ans,int k)
{
    if(idx == n)
    {
        if(ans.size() == k)
        {
            for(int i=0;i<k;i++)
            cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx) < k) return;
    subsequence(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    subsequence(arr,n,idx+1,ans,k);

}
int main()
{
    int n;
    cout<<"Enter the number:- ";
    cin>>n;
    int k;
    cout<<"Enter the length:- ";
    cin>>k;
    vector<int> v;
    int a[n];
    for(int i=0;i<n;i++)
    a[i] = i+1;
    subsequence(a,n,0,v,k);
    return 0;
}