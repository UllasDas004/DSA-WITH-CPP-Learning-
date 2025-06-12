#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a number:- ";
    cin>>str;
    string ans = "";
    int count = 1;
    char ch = str[0];
    for(int i=1;i<str.length();i++)
    {
        if(ch == str[i]) count++;
        else
        {
            ans += (to_string(count)+ch);
            count = 1;
            ch = str[i];
        }
    }
    ans += (to_string(count)+ch);
    cout<<str<<" = "<<ans;
    return 0;
}