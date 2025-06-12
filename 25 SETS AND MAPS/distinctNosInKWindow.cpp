#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> distinctInts(vector<int>& v,int k)
{
    int n = v.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++)
    mp[v[i]]++;
    ans.push_back(mp.size());
    int i=1,j=k;
    while(j<n)
    {
        mp[v[i-1]]--;
        if(mp[v[i-1]] == 0) mp.erase(v[i-1]);
        mp[v[j]]++;
        ans.push_back(mp.size());
        i++;
        j++;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the numbers with spaces:"<<endl;
    for(int i=0;i<n;i++) cin>>v[i];
    int k;
    cout<<"Enter the k:- ";
    cin>>k;
    vector<int> ans = distinctInts(v,k);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}