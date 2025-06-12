#include<iostream>
#include<string>
using namespace std;
int main()
{
    string binary;
    cout<<"Enter the binary number:- ";
    cin>>binary;
    int decimal = 0,n=0;
    for(int i=0;binary[i]!='\0';i++)
    n++;
    for(int i=0;i<n;i++)
    {
        char ch = binary[i];
        int num = ch - '0';
        decimal += (num*(1<<(n-i-1)));
    }
    cout<<binary<<" in decimal is "<<decimal;
    return 0;
}