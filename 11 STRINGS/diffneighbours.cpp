#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a string:- ";
    cin>>s;
    int count = 0;
    for(int i=0;s[i] != '\0';i++)
    {
        if(s.size() == 1)
        break;
        if(s.size() == 2 && s[0] != s[1])
        {
            count++;
            break;
        }
        if(i == 0)
        {
            if(s[i] != s[i-1])
            count++;
        }
        else if(i == s.length()-1)
        {
            if(s[i] != s[i-1])
            count++;
        }
        else if(s[i-1] != s[i] && s[i] != s[i+1])
        count++;
    }
    cout<<"There are "<<count<<" different neghbouring characters.";
    return 0;
}