#include<iostream>
using namespace std;
int gcd(int min,int max)
{
    if(max%min == 0)
    return min;
    gcd(max%min,min);
}
int main()
{
    int a,b;
    cout<<"Enter first number:- ";
    cin>>a;
    cout<<"Enter second number:- ";
    cin>>b;
    int min = a;
    int max = b;
    if(a>b)
    {
        min = b;
        max = a;
    }
    int ans = gcd(min,max);
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<ans;
    return 0;
}