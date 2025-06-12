#include<iostream>
using namespace std;
int power(int a,int b)
{
    if(a == 0) return 0;
    if(b == 0) return 1;
    return a*power(a,b-1); 
}
int main()
{
    int a,b;
    cout<<"Enter a positive number:- ";
    cin>>a;
    cout<<"Enter power:- ";
    cin>>b;
    int fact = power(a,b);
    cout<<a<<"^"<<b<<" = "<<fact;
    return 0;
}