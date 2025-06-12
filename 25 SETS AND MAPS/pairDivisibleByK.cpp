#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool validPairs(vector<int>& v,int k)
{
    int n = v.size();
    if(n%2 == 1) return false;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int r = v[i]%k;
        if(r<0) r += k;
        mp[r]++;
    }
    if(mp[0]%2 == 1) return false;
    mp.erase(0);
    for(auto ele : mp)
    {
        int r = ele.first;
        if(2*r == k && mp[r]%2 == 1) return false;
        if(mp[r] != mp[k-r]) return false;
    }
    return true;
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
    if(validPairs(v,k)) cout<<"There are possible pairs!"<<endl;
    else cout<<"There is not possible pairs!"<<endl;
    return 0;
}