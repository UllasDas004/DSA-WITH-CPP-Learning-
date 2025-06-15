#include<iostream>
using namespace std;
int factorial(int x)
{
    int fact = 1;
    if(x==0) return 1;
    for(int i=2;i<=x;i++) fact *= i;
    return fact;
}
int combination(int n,int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
int main()
{
    int n;
    cout<<"Enter row numbers:- ";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++) cout<<" ";
        for(int k=0;k<=i;k++) cout<<combination(i,k)<<" ";
        cout<<endl;
    }
    return 0;
}