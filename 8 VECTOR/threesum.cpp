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
    cout<<"Enter the target sum:- ";
    int x;
    cin>>x;
    if(n<3) return 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(v[i]+v[j]+v[k] == x) count++;
            }
        }
    }
    cout<<count;
    return 0;
}