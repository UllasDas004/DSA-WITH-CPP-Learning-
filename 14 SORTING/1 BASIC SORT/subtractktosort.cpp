#include<iostream>
#include<climits>
using namespace std;
float max(float a,float b)
{
    if(a>=b) return a;
    else return b;
}
float min(float a,float b)
{
    if(a<b) return a;
    else return b;
}
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
    float kMin = (float)INT_MIN;
    float kMax = (float)INT_MAX;
    bool flag = true;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>=a[i+1])
        kMin = max(kMin,(a[i]+a[i+1])/2.0);
        else
        kMax = min(kMax,(a[i]+a[i+1])/2.0);
        if(kMax<kMin)
        {
            flag = false;
            break;
        }
    }
    if(flag == false) cout<<"There is no integer.";
    else
    {
        if((kMin-(int)kMin)>0) kMin = (int)kMin + 1;
        kMax = (int)kMax;
        if(kMax<kMin) cout<<"There is no integer.";
        else if(kMax == kMin) cout<<"Only integer is "<<kMax<<".";
        else
        cout<<"Range of integers is ["<<kMin<<","<<kMax<<"].";
        return 0;
    }
}