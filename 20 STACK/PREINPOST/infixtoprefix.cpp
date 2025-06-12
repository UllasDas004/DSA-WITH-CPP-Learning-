#include<iostream>
#include<stack>
#include<string>
using namespace std;
int pr(char ch)
{
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
}
void evaluate(stack<string>& val,stack<char>& op)
{
    string val2 = val.top();
    val.pop();
    string val1 = val.top();
    val.pop();
    char ch = op.top();
    op.pop();
    string ans = "";
    ans += ch+val1+val2;
    val.push(ans);
}
int main()
{
    string s;
    cout<<"Enter the expression:- ";
    cin>>s;
    stack<string> val;
    stack<char> op;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48 ));
        else
        {
            if(op.size() == 0) op.push(s[i]);
            else if(pr(op.top())<pr(s[i])) op.push(s[i]);
            else
            {
                while(op.size() && pr(op.top())>=pr(s[i]))
                evaluate(val,op);
                op.push(s[i]);
            }
        }
    }
    while(op.size())
    evaluate(val,op);
    cout<<s<<" = "<<val.top();
    return 0;
}