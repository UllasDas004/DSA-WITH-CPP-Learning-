#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int min = a[0];
    for(int i=0;i<=n-1;i++)
    {
        if(a[i]<min) min = a[i];
    }
    cout<<"minimum element is "<<min;
    return 0;
}