#include<iostream>
#include<vector>
using namespace std;
vector<int> st,lazy;
void buildTree(vector<int>& arr,int i,int lo,int hi)
{
    if(lo == hi)
    {
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i] = st[2*i+1] + st[2*i+2];
}
void updateRange(int i,int lo,int hi,int l,int r,int val)
{
    // pending lazy updates
    if(lazy[i] != 0)
    {
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize*lazy[i];
        if(lo != hi)
        {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(hi < l || lo > r) return; // outside range case
    if(lo >= l && r >= hi) // range update case
    {
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize*val;
        if(lo != hi)
        {
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    int mid = lo + (hi-lo)/2;
    updateRange(2*i+1,lo,mid,l,r,val);
    updateRange(2*i+2,mid+1,hi,l,r,val);
    st[i] = st[2*i+1] + st[2*i+2];
}
int getSum(int i,int lo,int hi,int l,int r)
{
    // pending lazy updates
    if(lazy[i] != 0)
    {
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize*lazy[i];
        if(lo != hi)
        {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(hi < l || lo > r) return 0;
    if(lo >= l && r >= hi) return st[i];
    int mid = lo + (hi-lo)/2;
    return getSum(2*i+1,lo,mid,l,r) + getSum(2*i+2,mid+1,hi,l,r);
}
int main()
{
    vector<int> arr = {1,4,2,8,6,4,9,3};
    int n = arr.size();
    st.resize(4*n);
    lazy.resize(4*n,0);
    buildTree(arr,0,0,n-1);
    cout<<"Sum is "<<getSum(0,0,n-1,1,3)<<endl;
    updateRange(0,0,n-1,2,5,5);
    cout<<"Sum is "<<getSum(0,0,n-1,4,7)<<endl;
    return 0;
}