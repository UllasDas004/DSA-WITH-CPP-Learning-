#include<iostream>
#include<vector>
using namespace std;
void reversePart(vector<int>& v,int i,int j)
{
    for(;i<j;i++,j--)
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
    cout<<"Input vector."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    // Finding pivot index
    int idx = -1;
    for(int i=v.size()-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {
            idx = i;
            break;
        }
    }
    // Finding next permutation
    if(idx == -1) reversePart(v,0,v.size()-1);  // If it is the last permutation then sorting
    else
    {
        reversePart(v,idx+1,v.size()-1);    // First reverse the part just after idx
        int j=-1;
        for(int i=idx+1;i<v.size();i++)     // Then swapping the idx element
        {                                   // and the element just greater
            if(v[i]>v[idx])                 // than idx element
            {
                j=i;
                break;
            }
        }
        int temp = v[idx];
        v[idx] = v[j];
        v[j] = temp;
    }
    
    cout<<"Next permutation."<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}