#include<iostream>
using namespace std;
int main()
{
    int decimal;
    cout<<"Enter the decimal number:- ";
    cin>>decimal;
    int num = decimal,setbits = 0;
    while(num>0)
    {
        setbits++;
        num = num & (num-1);
    }
    cout<<"Number of setbits in "<<decimal<<" is "<<setbits;
    return 0;
}