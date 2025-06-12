#include<iostream>
#include<vector>
using namespace std;
void change(vector<int>& a)
{
    a[0] = 100;
}
int main()
{
    vector<int> v;
    int n;
    cout<<"Enter the size of vector:- ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Enter number"<<i+1<<":- ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    change(v);
    cout<<"After updation."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}