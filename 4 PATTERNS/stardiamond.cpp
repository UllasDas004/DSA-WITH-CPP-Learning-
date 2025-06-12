#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the row number:- ";
    cin>>n;
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=n-i;j++) cout<<" ";
        for(int k=1;k<=2*i-1&&i<=n;k++) cout<<"*";
        for(int j=i-n-1;i>n&&j>=0;j--) cout<<" ";
        for(int k=2*(2*n-i)-1;k>=1&&i>n;k--) cout<<"*";
        cout<<endl;
    }
    return 0;
}