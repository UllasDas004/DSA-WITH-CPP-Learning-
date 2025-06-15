#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[] = {2,1,5,5,5,5,6,6,6,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int j = i;
        while(j<n-1 && arr[j] == arr[j+1]) j++;
        int count = j-i;
        i = j;
        if(count>=n/3) ans.push_back(arr[i]);
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}