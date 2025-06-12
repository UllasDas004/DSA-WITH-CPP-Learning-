#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"Enter the target sum:- ";
    int target;
    cin>>target;
    int len,minlen = n+1;
    int sum = 0;
    for(int i=0,j=0;j<n;j++)
    {
        sum += a[j];
        while(sum >= target)
        {
            len = j-i+1;
            if(minlen>len) minlen = len;
            sum -= a[i];
            i++;
        }
    }
    if(minlen != n+1) cout<<"The minimum length of subarray is "<<minlen<<".";
    else cout<<"The minimum length of subarray is 0.";
    return 0;
}