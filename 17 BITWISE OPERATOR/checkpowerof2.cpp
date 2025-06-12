#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number:- ";
    cin>>n;
    int num = n;
    bool flag = true;
    while(num>1)
    {
        if(num%2 == 1)
        {
            flag = false;
            break;
        }
        num /= 2;
    }
    if(flag == true) cout<<n<<" is power of 2.";
    else cout<<n<<" is not power of 2.";
    return 0;
}