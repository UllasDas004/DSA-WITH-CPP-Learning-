#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Enter the number string:- ";
    string s;
    cin>>s;
    int n = 0;
    for(int i=0;i<s.length();i++)
    n = n*10 + ((int)s[i]-48);
    cout<<n<<endl;
    return 0;
}