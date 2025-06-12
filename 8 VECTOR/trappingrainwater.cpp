#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> height;
    int n;
    cout<<"Enter the size of vector:- ";
    cin>>n;
    cout<<"Enter heights."<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        height.push_back(x);
    }
    int a[n];
    a[0] = -1;
    // Building previous greatest elemnet array
    int max = height[0];
    for(int i=1;i<n;i++)
    {
        a[i] = max;
        if(max<height[i]) max=height[i];
    }
    // Building minimum value array
    max = height[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(max<a[i]) a[i] = max;
        if(max<height[i]) max=height[i];
    }
    int water = 0;
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]>height[i]) water += (a[i] - height[i]);
    }
    cout<<"Amount of trapped water is "<<water<<".";
    return 0;
}