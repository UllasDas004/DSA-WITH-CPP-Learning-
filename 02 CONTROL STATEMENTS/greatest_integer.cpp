#include<iostream>
using namespace std;
int main()
{
    float n;
    cout<<"Enter any number:- ";
    cin>>n;
    if(n>=0)
    cout<<"Absolute value of "<<n<<" is "<<(int)n;
    else
    cout<<"Absolute value of "<<n<<" is "<<(int)n-1;
    return 0;
}