#include<iostream>
#include<string>
using namespace std;
void parenthesis(string ans,int n,int noo,int noc)
{
    if(noc == n)
    {
        cout<<ans<<endl;
        return;
    }
    if(noo<n) parenthesis(ans+'(',n,noo+1,noc);
    if(noo>noc) parenthesis(ans+')',n,noo,noc+1);
}
int main()
{
    int n;
    cout<<"Enter the number of pairs:- ";
    cin>>n;
    parenthesis("",n,0,0);
}