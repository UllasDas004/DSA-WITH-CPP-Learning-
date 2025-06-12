#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& res)
{
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<=b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }
    if(i == a.size())
    {
        while(j < b.size())
        res[k++] = b[j++];
    }
    else if(j == b.size())
    {
        while(i < a.size())
        res[k++] = a[i++];
    }
}
void mergesort(vector<int>& v)
{
    int n = v.size();
    if(n == 1) return;
    int n1 = n/2 , n2 = n - n/2;
    vector<int> a(n1),b(n2); //PART ARRAYS
    // COPY AND PASTE IN THE PART ARRAYS
    for(int i=0;i<n1;i++)
    a[i] = v[i];
    for(int i=0;i<n2;i++)
    b[i] = v[i+n1];
    // CALLING AGAIN FOR MAKING MORE PARTS
    mergesort(a);
    mergesort(b);
    // MERGING THE PART SORTED ARRAYS
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element"<<i+1<<":- ";
        cin>>v[i];
    }
    cout<<"Before sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    cout<<endl;
    mergesort(v);
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;
}