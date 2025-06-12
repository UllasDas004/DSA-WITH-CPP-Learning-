#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& v)
{
    for(int i=0,j=v.size()-1;i<=j;i++,j--)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void reversepart(vector<int>& v,int i,int j)
{
    for(;i<=j;i++,j--)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
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
    int k;
    cout<<"Enter the step:- ";
    cin>>k;
    k = k%(v.size()-1);
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;

    reverse(v);
    reversepart(v,0,k-1);
    reversepart(v,k,v.size()-1);

    cout<<"Rotated array by "<<k<<" step."<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}