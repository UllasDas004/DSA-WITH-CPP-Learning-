#include<iostream>
#include<string>
using namespace std;
int main()
{
    int decimal;
    cout<<"Enter the decimal number:- ";
    cin>>decimal;
    string binary = "";
    int num = decimal;
    while(num > 0)
    {
        if(num%2 == 0)
        binary = '0' + binary;
        else
        binary = '1' + binary;
        num = num/2;
    }
    cout<<decimal<<" in binary is "<<binary;
    return 0;
}