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
    ans += val1+val2+ch;
    val.push(ans);
}
int solve(string post)
{
    stack<int> st;
    for(int i=0;i<post.length();i++)
    {
        if(post[i]>=48 && post[i]<=57) st.push((int)(post[i]-48));
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            char ch = post[i];
            if(ch == '+') st.push(val1+val2);
            else if(ch == '-') st.push(val1-val2);
            else if(ch == '*') st.push(val1*val2);
            else if(ch == '/') st.push(val1/val2);
        }
    }
    return st.top();
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
    int ans = solve(val.top());
    cout<<s<<" = "<<ans;
    return 0;
}