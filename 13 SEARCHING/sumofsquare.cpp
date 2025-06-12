#include<iostream>
#include<cmath>
using namespace std;
bool checkSqrt(int a)
{
    int n = sqrt(a);
    if(n*n == a) return true;
    else return false;
}
int main()
{
    int c;
    cout<<"Enter a number:- ";
    cin>>c;
    int i=0,j=c;
    bool flag = false;
    while(i<=j)
    {
        if(checkSqrt(i) && checkSqrt(j))
        {
            cout<<c<<" is sum of squares of "<<sqrt(i)<<" and "<<sqrt(j);
            flag = true;
            break;
        }
        else if(!checkSqrt(j))
        {
            j = (int)sqrt(j)*(int)sqrt(j);
            i = c - j;
        }
        else
        {
            i = ((int)sqrt(i)+1)*((int)sqrt(i)+1);
            j = c - i;
        }
    }
    if(flag == false) cout<<"There are no such integers.";
    return 0;
}