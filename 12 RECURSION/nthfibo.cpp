#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n==1||n==2) return 1;
    return fibo(n-1) + fibo(n-2);
}
int main()
{
    int n;
    cout<<"Enter the position of term:- ";
    cin>>n;
    cout<<n<<"th term is "<<fibo(n);
    return 0;
}