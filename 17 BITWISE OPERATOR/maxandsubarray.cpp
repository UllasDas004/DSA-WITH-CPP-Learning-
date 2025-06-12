#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:-";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number"<<i+1<<":- ";
        cin>>a[i];
    }
    int count = 0,ans = 0,max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i] > max)
        {
            count = 1;
            max = a[i];
            if(ans<count) ans = count;
        }
        else if(a[i] == max)
        {
            count++;
            if(ans<count) ans = count;
        }
        else if(a[i] < max)
        count = 0;
    }
    cout<<"The length of longest maximum and subarray is "<<ans;
    return 0;
}