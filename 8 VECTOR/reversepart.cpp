#include<iostream>
#include<vector>
using namespace std;
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
    int k1,k2;
    cout<<"Enter the starting position:- ";
    cin>>k1;
    cout<<"Enter the ending position:- ";
    cin>>k2;
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    for(int i=k1-1,j=k2-1;i<=j;i++,j--)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    cout<<"Desired vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}