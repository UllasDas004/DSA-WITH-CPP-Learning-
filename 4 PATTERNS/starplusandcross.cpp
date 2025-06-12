#include<iostream>
using namespace std;
int main()
{
    int n;
    char ch;
    cout<<"Enter the row number:- ";
    cin>>n;
    cout<<"What pattern do you want(p/c):- ";
    cin>>ch;
    if(ch=='p')
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==n/2+1) cout<<"*";
                else if(j==n/2+1) cout<<"*";
                else cout<<" ";
            }
            cout<<endl;
        } 
    }
    else if(ch=='c')
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j || (i+j) == n+1)
                cout<<"*";
                else
                cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}