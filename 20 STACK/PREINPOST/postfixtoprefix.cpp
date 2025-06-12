#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s = "79+4*8/3-";
    stack<string> val;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=48 && s[i]<=57)
        val.push(to_string(s[i]-48));
        else
        {
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = "";
            ans += s[i]+val1+val2;
            val.push(ans);
        }
    }
    cout<<s<<" = "<<val.top();
    return 0;
}