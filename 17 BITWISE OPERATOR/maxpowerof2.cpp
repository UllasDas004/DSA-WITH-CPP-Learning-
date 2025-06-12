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
    cout<<"Maximum number which is power of two closest to "<<decimal<<" is "<<ans;
    return 0;
}