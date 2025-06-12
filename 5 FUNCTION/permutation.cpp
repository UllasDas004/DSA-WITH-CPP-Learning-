#include<iostream>
using namespace std;
int factorial(int x)
{
    int fact = 1;
    for(int i=2;i<=x;i++) fact *= i;
    return fact;
}
int permutation(int n,int r)
{
    return factorial(n)/factorial(n-r);
}
int combination(int n,int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
int main()
{
    int n,r;
    cout<<"Enter n:- ";
    cin>>n;
    cout<<"Enter r:- ";
    cin>>r;
    if(n<r) cout<<"Invalid expression";
    else 
    {
        cout<<n<<"p"<<r<<" = "<<permutation(n,r)<<endl;
        cout<<n<<"c"<<r<<" = "<<combination(n,r)<<endl;
    }
    return 0;
}