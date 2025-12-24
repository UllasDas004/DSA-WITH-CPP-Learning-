#include<iostream>
#include<vector>
using namespace std;
int findSum(vector<int>& ft,int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += ft[idx];
        idx -= (idx & -(idx));
    }
    return sum;
}
void update(vector<int>& ft,int val,int idx)
{
    while(idx < ft.size())
    {
        ft[idx] += val;
        idx += (idx & -(idx));
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> a(n+1),fenwickTree(n+1,0);
    cout<<"Enter the elements with spaces:- ";
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int x = a[i],idx = i;
        update(fenwickTree,a[i],i);
    }
    for(int i=1;i<=n;i++) cout<<fenwickTree[i]<<" ";
    cout<<endl;
    int q;
    cout<<"Enter number of queries:- ";
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int op;
        cout<<"Enter type of operation(1 for Sum/2 for update):- ";
        cin>>op;
        if(op == 1)
        {
            int l,r;
            cout<<"Enter the left and right indices(1 indexed):- ";
            cin>>l>>r;
            cout<<findSum(fenwickTree,r)-findSum(fenwickTree,l-1)<<endl;
        }
        else
        {
            int val,idx;
            cout<<"Enter the index to update(1 indexed):- ";
            cin>>idx;
            cout<<"Enter the value:- ";
            cin>>val;
            update(fenwickTree,val-a[idx],idx);
            a[idx] = val;
        }
    }
}