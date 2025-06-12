#include<iostream>
using namespace std;
float power(int a,int b)
{
    if(b == 0) return 1;
    if(a == 1 || a == 0) return a;
    int ans;
    if(b>0)
    {
        ans = power(a,b/2);
        if(b%2 == 0) return ans*ans;
        else return ans*ans*a;
    } 
    else
    {
        b = -(b);
        ans = power(a,b/2);
        if(b%2 == 0) return 1/((float)(ans*ans));
        else return 1/((float)(ans*ans*a));
    }
}
int main()
{
    int a;
    cout<<"Enter a positive number:- ";
    cin>>a;
    int b;
    cout<<"Enter the power:- ";
    cin>>b;
    cout<<a<<"^"<<b<<" = "<<power(a,b);
    return 0;
}