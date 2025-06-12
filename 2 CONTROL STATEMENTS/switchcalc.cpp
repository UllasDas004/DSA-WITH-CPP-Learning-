#include<iostream>
using namespace std;
int main()
{
    float a,b;
    char ch;
    cout<<"Enter expression:- ";
    cin>>a>>ch>>b;
    switch (ch)
    {
        case '+' : 
            cout<<a<<" + "<<b<<" = "<<a+b;
            break;
        case '-' : 
            cout<<a<<" - "<<b<<" = "<<a-b;
            break;
        case '*' : 
            cout<<a<<" * "<<b<<" = "<<a*b;
            break;
        case '/' : 
            cout<<a<<" + "<<b<<" = "<<a/b;
            break;
        case '%' : 
            cout<<a<<" % "<<b<<" = "<<(int)a%(int)b;
            break;
        default : 
            cout<<"Invalid expression.";
            break;
        return 0;    
    }
}