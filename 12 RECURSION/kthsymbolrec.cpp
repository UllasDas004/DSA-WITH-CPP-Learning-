#include<iostream>
using namespace std;
int symbol(int n,int k)
{
    if(n == 1) return 0;
    int ans;
    if(k%2 == 0) ans = symbol(n-1,k/2);
    else ans = symbol(n-1,k/2+1);
    if(k%2 == 0 && ans == 0) return 1;
    else if(k%2 == 0 && ans == 1) return 0;
    else return ans;
}
int main()
{
    int n,k;
    cout<<"Enter the row number:- ";
    cin>>n;
    cout<<"Enter the element number:- ";
    cin>>k;
    int ans = symbol(n,k);
    cout<<ans;
    return 0;
}