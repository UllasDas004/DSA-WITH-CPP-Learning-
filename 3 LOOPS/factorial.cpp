#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number:- ";
    cin>>num;
    int r,p=1;
    if(num == 0) cout<<"0! = 1";
    else
    {
        for(int i=1;i<=num;i++)
        p *= i;
    }
    cout<<num<<"! = "<<p;
    return 0;
}