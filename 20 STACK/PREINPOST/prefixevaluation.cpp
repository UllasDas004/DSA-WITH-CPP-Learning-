#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s = "-/*+79483";
    stack<int> val;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>=48 && s[i]<=57) val.push((int)(s[i]-48));
        else
        {
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            char ch = s[i];
            if(ch == '+') val.push(val1+val2);
            else if(ch == '-') val.push(val1-val2);
            else if(ch == '*') val.push(val1*val2);
            else if(ch == '/') val.push(val1/val2);
        }
    }
    cout<<s<<" = "<<val.top();
    return 0;
}