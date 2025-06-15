#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number:- ";
    cin>>num;
    int r,count=0,s=0,sum=0;
    int a = num;
    if(num<0) a = -(num);
    if(a == 0) count = 1;
    while(a != 0)
    {
        r = a % 10;
        sum += r;
        s = s*10 + r;
        count++;
        a /= 10;
    }
    cout<<"There are "<<count<<" digits in "<<num<<endl;
    cout<<"Sum of digits of "<<num<<" is "<<sum<<endl;
    cout<<"Reverse of "<<num<<" is "<<s<<"."<<endl;
    if(s == num) cout<<num<<" is a palindrome number.";
    else cout<<num<<" is not a palindrome number.";
    return 0;
}