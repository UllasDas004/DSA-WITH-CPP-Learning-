#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a string of combination of ( or ):- ";
    cin>>s;
    stack<char> st;
    bool flag = true;
    if(s.length()%2 == 1)
    {
        cout<<s<<" is not balanced"<<endl;
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(') st.push('(');
        else if(s[i] == ')')
        {
            if(st.size() == 0)
            {
                flag = false;
                break;
            }
            else if(st.top() == '(') st.pop(); 
        }
    }
    if(flag && st.size() == 0) cout<<s<<" is balanced"<<endl;
    else cout<<s<<" is not balanced"<<endl;
    return 0;
}