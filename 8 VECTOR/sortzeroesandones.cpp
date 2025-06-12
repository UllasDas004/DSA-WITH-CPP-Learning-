#include<iostream>
#include<vector>
using namespace std;
void sort01(vector<int>& v)
{
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v[i] == 0 && i<j) i++;
        if(v[j] == 1 && i<j) j--;
        if(v[i] == 1 && v[j] == 0 && i<j)
        {
            v[i] = 0;
            v[j] = 1;
            i++;
            j--;
        }
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
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    sort01(v);
    cout<<"After sorting."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}