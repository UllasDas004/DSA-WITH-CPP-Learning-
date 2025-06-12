#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort012(vector<int>& v)
{
    int lo=0,mid=0,hi=v.size()-1;
    while(mid<=hi)
    {
        if(v[mid] == 2)
        {
            swap(&v[mid],&v[hi]);
            hi--;
        }
        else if(v[mid] == 0)
        {
            swap(&v[mid],&v[lo]);
            lo++;
            mid++;
        }
        else mid++;
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
        cout<<"Enter number"<<i+1<<"(only 0,1 2):- ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    sort012(v);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}