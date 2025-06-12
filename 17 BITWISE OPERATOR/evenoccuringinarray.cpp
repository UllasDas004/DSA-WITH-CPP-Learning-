#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>arr[i];
    }
    int b = 0;
    for(int i=0;i<n;i++)
    b ^= arr[i];
    int a = 0;
    if(b == arr[0])
    a = arr[1];
    else a = arr[0];
    cout<<"a = "<<a<<" b = "<<b;
    return 0;
}