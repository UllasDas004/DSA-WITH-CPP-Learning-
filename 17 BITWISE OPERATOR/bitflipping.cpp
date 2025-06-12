#include<iostream>
using namespace std;
int main()
{
    int decimal;
    cout<<"Enter the decimal number:- ";
    cin>>decimal;
    int num = decimal,ans = 0;
    while(num>0)
    {
        ans = num;
        num = num & (num-1);
    }
    int flip = (2*ans - 1) ^ decimal;
    cout<<"Flip number of "<<decimal<<" is "<<flip;
    return 0;
}