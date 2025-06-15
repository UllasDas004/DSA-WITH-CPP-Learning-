#include<iostream>
using namespace std;
int multiply(int x,int fact[],int res_size)
{
    int carry = 0;
    for(int i=0;i<res_size;i++)
    {
        int prod = fact[i]*x + carry;
        fact[i] = prod%10;
        carry = prod/10;
    }
    while(carry)
    {
        fact[res_size] = carry%10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}
void fact(int n)
{
    int fact[1000];
    fact[0] = 1;
    int res_size = 1;
    for(int x=2;x<=n;x++)
    res_size = multiply(x,fact,res_size);
    cout<<n<<"! = ";
    for(int i=res_size-1;i>=0;i--)
    cout<<fact[i];

}
int main()
{
    int n;
    cout<<"Enter the number:- ";
    cin>>n;
    fact(n);
    return 0;
}