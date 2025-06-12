#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number:- ";
    cin>>n;
    int num = n;
    if((num & (num-1)) == 0) cout<<n<<" is power of 2.";
    else cout<<n<<" is power not of 2.";
    return 0;
}