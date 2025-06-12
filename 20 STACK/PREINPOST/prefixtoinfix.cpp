#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s = "-/*+79483";
    stack<string> val;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>=48 && s[i]<=57)
        val.push(to_string(s[i]-48));
        else
        {
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = "";
            ans += val1+s[i]+val2;
            val.push(ans);
        }
    }
    cout<<s<<" = "<<val.top();
    return 0;
}