#include<iostream>
#include<vector>
using namespace std;
void sumtriangle(vector<int>& v,int n)
{
    if(n == 0) return;
    for(int j=0;j<n;j++)
    cout<<v[j]<<" ";
    for(int j=0;j<n;j++)
    v[j] = v[j] + v[j+1];
    cout<<endl;
    sumtriangle(v,n-1);
}
int main()
{
    vector<int> v;
    cout<<"Enter the number of elements:- ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        int x;
        cin>>x;
        v.push_back(x);
    }
    sumtriangle(v,n);
    // for(;n>=0;n--)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<v[j]<<" ";
    //     for(int j=0;j<n;j++)
    //     v[j] = v[j] + v[j+1];
    //     cout<<endl;
    // }
    // return 0;
}