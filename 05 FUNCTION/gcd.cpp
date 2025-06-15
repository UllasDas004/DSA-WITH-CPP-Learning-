#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    int min = x,max = y;
    if(y<x) 
    {
        min  = y;
        max = x;
    }
    while(min>0)
    {
        int temp = max % min;
        max = min;
        min = temp;
    }
    return max;
}
int main()
{
    int a,b;
    cout<<"Enter firest number:- ";
    cin>>a;
    cout<<"Enter second number:- ";
    cin>>b;
    cout<<"GCD of "<<a<<","<<b<<" is "<<gcd(a,b);
    return 0;
} 