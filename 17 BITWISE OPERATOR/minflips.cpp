#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cout<<"Enter the first decimal number:- ";
    cin>>x;
    cout<<"Enter the second decimal number:- ";
    cin>>y;
    int num = x ^ y;
    int ans = 0;
    while(num > 0)
    {
        ans++;
        num = num & (num-1);
    }
    cout<<"Minimum flips required to covert "<<x<<" to "<<y<<" is "<<ans;
    return 0;
}