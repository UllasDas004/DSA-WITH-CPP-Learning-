#include<iostream>
using namespace std;
int main()
{
    int n,flag=1;
    cout<<"Enter a number:- ";
    cin>>n;
    if(n==0 || n==1) cout<<n<<" Is neither a prime number nor composite number.";
    else
    {
        for(int i=2;i<=n-1;i++)
        {
            if(n%i == 0)
            {
                flag = 0;
                break;
            } 
        }
    }
    if(flag == 1) cout<<n<<" Is a prime number.";
    else cout<<n<<" Is a composite number.";
    return 0;
}