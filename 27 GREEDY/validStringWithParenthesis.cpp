#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<pair<char,int>> st;
    vector<int> idx;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(') st.push({s[i],i});
        else if(s[i] == ')')
        {
            if(st.size() == 0) idx.push_back(i);
            else if(st.top().first == '(') st.pop();
        }
    }
    while(st.size())
    {
        idx.push_back(st.top().second);
        st.pop();
    }
    sort(idx.begin(),idx.end());
    string ans = "";
    int j = 0;
    for(int i=0;i<s.length();i++)
    {
        if(i == idx[j]) j++;
        else ans.push_back(s[i]);
    }
    cout<<s<<" = "<<ans<<endl;
    return 0;
}