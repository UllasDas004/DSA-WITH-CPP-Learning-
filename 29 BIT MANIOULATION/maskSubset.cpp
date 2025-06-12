#include<iostream>
using namespace std;
int main()
{
    int mask;
    cin>>mask;
    for(int g=mask;g!=0;g=((g-1)&mask))
    cout<<g<<" ";
    cout<<endl;
    return 0;
}