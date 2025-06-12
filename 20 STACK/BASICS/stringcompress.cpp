#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a string:- ";
    cin>>s;
    string ans = "";
    stack<char> st;
    ans += s[0];
    st.push(s[0]);
    for(int i=1;i<s.length();i++)
    {
        if(st.top() == s[i]) continue;
        ans += s[i];
        st.push(s[i]);
    }
    cout<<ans<<endl;
    return 0;
}