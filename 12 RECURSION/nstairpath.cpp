#include<iostream>
using namespace std;
int stair(int n)
{
    if(n == 2 || n == 1) return n;
    return stair(n-2) + stair(n-1);
}
int main()
{
    int n;
    cout<<"Enter total number of stairs:- ";
    cin>>n;
    cout<<"Total number of ways are "<<stair(n);
}