#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number:- ";
    cin>>num;
    int n = num;
    bool flag = false;
    if(n<=0) flag = false; // ugly number is must be positive
    while(n%2 == 0) n /= 2;
    while(n%3 == 0) n /= 3;
    while(n%5 == 0) n /= 5;
    if(n == 1) flag = true;
    if(flag) cout<<num<<" is an ugly number.";
    else cout<<num<<" is not an ugly number.";
    return 0;
}