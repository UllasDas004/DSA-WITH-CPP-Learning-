#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& par,int n)
{
    // returns the leader of the group in which n belongs to
    if(par[n] == n) return par[n];
    return par[n] = find(par,par[n]);
}
void Union(vector<int>& par,vector<int>& rank,int a,int b)
{
    // adds the groups in which a and b belongs to
    a = find(par,a);
    b = find(par,b);
    if(a == b) return;
    if(rank[a] >= rank[b])
    {
        par[b] = a;
        rank[a]++;
    }
    else
    {
        par[a] = b;
        rank[b]++;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector<int> par(n);
    cout<<"Enter the elements with spaces. \n";
    for(int i=0;i<n;i++) cin>>par[i];
    vector<int> rank(n,1);
    int q;
    cout<<"Enter number of queries:- ";
    cin>>q;
    cout<<"Enter 1 for union and 2 for find.\n";
    while(q--)
    {
        int ch;
        cout<<"Enter your choice:- ";
        cin>>ch;
        if(ch == 1)
        {
            int a,b;
            cout<<"Enter the element whose groups you want to union with spaces.\n";
            cin>>a>>b;
            Union(par,rank,a,b);
            cout<<"Groups of "<<a<<" and "<<b<<" is added!\n";
        }
        else if(ch == 2)
        {
            int a;
            cout<<"Enter the element whose leader you want to find.\n";
            cin>>a;
            cout<<"Leader of the group "<<a<<" belongs to is "<<find(par,a);
        }
        else cout<<"Invalid choice ID!\n";
    }
    return 0;
}