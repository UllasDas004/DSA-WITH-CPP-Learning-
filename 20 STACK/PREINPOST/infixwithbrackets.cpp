#include<iostream>
#include<stack>
#include<string>
using namespace std;
int pr(char ch)
{
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
}
int solve(int v1,int v2,char ch)
{
    if(ch == '+') return v1+v2;
    if(ch == '-') return v1-v2;
    if(ch == '*') return v1*v2;
    if(ch == '/') return v1/v2;
}
void evaluate(stack<int>& val,stack<char>& op)
{
    int val2 = val.top();
    val.pop();
    int val1 = val.top();
    val.pop();
    char ch = op.top();
    op.pop();
    int ans = solve(val1,val2,ch);
    val.push(ans);
}
int main()
{
    string s;
    cout<<"Enter the expression:- ";
    cin>>s;
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=48 && s[i]<=57) val.push((int)(s[i]-48));
        else
        {
            if(op.size() == 0) op.push(s[i]);
            else if(s[i] == '(' || op.top() == '(') op.push(s[i]);
            else if(s[i] == ')')
            {
                while(op.top() != '(')
                evaluate(val,op);
                op.pop();
            }
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
    {
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<s<<" = "<<val.top();
    return 0;
}