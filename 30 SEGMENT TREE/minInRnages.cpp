#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void buildTree(vector<int>& st,vector<int>& v,int i,int lo,int hi)
{
    if(lo == hi)
    {
        st[i] = v[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(st,v,2*i+1,lo,mid);
    buildTree(st,v,2*i+2,mid+1,hi);
    st[i] = min(st[2*i+1],st[2*i+2]);
}
int getMin(vector<int>& st,int i,int lo,int hi,int& l,int& r)
{
    if(hi < l || lo > r) return INT_MAX; // range outside
    if(l <= lo && hi <= r) return st[i];
    int mid = lo + (hi-lo)/2;
    return min(getMin(st,2*i+1,lo,mid,l,r),getMin(st,2*i+2,mid+1,hi,l,r));
}
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements with spaces:\n";
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> st(4*n);
    buildTree(st,v,0,0,n-1);
    int q;
    cout<<"Enter number of queries:- ";
    cin>> q;
    cout<<"Enter the queries:\n";
    for(int i=0;i<q;i++)
    {
        int l,r;
        cout<<"Enter the left and right indices of query "<<i+1<<" :"<<endl;
        cin>>l>>r;
        if(l<0 || r>=n || l>r) cout<<"Invalid query range!"<<endl;
        else cout<<"The minimum element is the range ["<<l<<","<<r<<"] is "<<getMin(st,0,0,n-1,l,r)<<endl;
    }
    return 0;
}