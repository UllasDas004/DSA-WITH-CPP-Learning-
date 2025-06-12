#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the row number:- ";
    cin>>n;
    for(int i=1;i<=2*n-1;i++) cout<<i;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int a=1;
        for(int j=n-i;j>=1;j--,a++) cout<<a;;
        for(int k=1;k<=2*i-1;k++,a++) cout<<" ";
        for(int j=n-i;j>=1;j--,a++) cout<<a;
        cout<<endl;
    }
    return 0;
}