#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"Original array."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    vector<int> v(n,0);
    int x = 0;
    for(int i=0;i<n;i++)
    {
        int min = INT_MAX,mindx = -1;
        for(int j=0;j<n;j++)
        {
            if(v[j] == 1) continue;
            else
            {
                if(min>a[j])
                {
                    min = a[j];
                    mindx = j;
                }
            }
        }
        a[mindx] = x;
        x++;
        v[mindx] = 1;
    }
    cout<<endl<<"Replaced array."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}