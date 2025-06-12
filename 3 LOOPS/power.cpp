#include<iostream>
using namespace std;
int main()
{
    int num,power;
    cout<<"Enter a number:- ";
    cin>>num;
    cout<<"Enter power:- ";
    cin>>power;
    float p=1;
    int b=power;
    if(power<0) b = -(power);
    for(int i=1;i<=b;i++)
    p *= num;
    if(num == 0 && power == 0) cout<<"Not defined";
    else if(power>=0) cout<<num<<"^"<<power<<" = "<<p;
    else cout<<num<<"^"<<power<<" = "<<1/p;
    return 0;
}